#include <evhttp.h>
#include <sys/queue.h>

#include "nkane/listener.h"
#include "nkane/listener_handler.h"
#include "nkane/reply.h"

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

Listener::Listener (int port, ListenerHandler* handler)
{
    this->port = port;
    this->handler = handler;
}

string Listener::get_header(struct evhttp_request *r, const char* key)
{
    const char *val = evhttp_find_header(evhttp_request_get_input_headers(r), key);
    return (val == NULL) ? "" : val;
}

map<string, string> Listener::get_headers_map(const struct evkeyvalq *headers)
{
    map<string, string> headers_map;
    struct evkeyval *header;

    TAILQ_FOREACH(header, headers, next) {
        headers_map[header->key] = header->value;
    }

    return headers_map;
}

void Listener::incoming(struct evhttp_request *r, void *args)
{
    ListenerHandler* handler = (ListenerHandler*) args;

    string url = evhttp_request_get_uri(r);
    map<string, string> headers_map = Listener::get_headers_map(evhttp_request_get_input_headers(r));

    Reply result;
    switch (r->type) {
    case EVHTTP_REQ_GET:
      result = handler->process_get(url, headers_map);
      break;
    default:
      cout << "Unsupported method" << endl;
      result.append_body("Unsupported method");
      break;
    }

    struct evbuffer *buffer = evbuffer_new();
    struct evkeyvalq *headers = evhttp_request_get_output_headers(r);
    
    map<string, string>::const_iterator itr;
    for (itr = result.get_headers().begin(); itr != result.get_headers().end(); ++ itr){
      evhttp_add_header(headers, itr->first.c_str(), itr->second.c_str());

    }
    evbuffer_add_printf(buffer, "%s", result.get_body().c_str());

    evhttp_send_reply(r, HTTP_OK, "OK", buffer);
    evbuffer_free(buffer);
}

void Listener::run()
{
    cout <<"Starting on port:"<< port << endl;

    base = event_base_new();
    server = evhttp_new(base);

    evhttp_bind_socket(server, "0.0.0.0", port);
    evhttp_set_gencb(server, Listener::incoming, this->handler);
    event_base_dispatch(base);
}
