#include <evhttp.h>
#include <sys/queue.h>

#include "nkane/webapp.h"
#include "nkane/request_handler.h"
#include "nkane/reply.h"
#include "nkane/routes.h"

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

WebApp::WebApp (int port, Routes* routes)
{
    this->port = port;
		this->routes = routes;
}

string WebApp::get_header(struct evhttp_request *r, const char* key)
{
    const char *val = evhttp_find_header(evhttp_request_get_input_headers(r), key);
    return (val == NULL) ? "" : val;
}

map<string, string> WebApp::get_headers_map(const struct evkeyvalq *headers)
{
    map<string, string> headers_map;
    struct evkeyval *header;

    TAILQ_FOREACH(header, headers, next) {
        headers_map[header->key] = header->value;
    }

    return headers_map;
}

void WebApp::incoming(struct evhttp_request *r, void *args)
{
    Routes* routes = (Routes*) args;

    string url = evhttp_request_get_uri(r);
    map<string, string> headers_map = WebApp::get_headers_map(evhttp_request_get_input_headers(r));

    Reply result;
		//TODO: here check to see if the handler as the required
		// interface.

    switch (r->type) {
    case EVHTTP_REQ_GET:
      result = routes->process_get(url, headers_map);
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

void WebApp::run()
{
    cout <<"Starting on port:"<< port << endl;

    base = event_base_new();
    server = evhttp_new(base);

    evhttp_bind_socket(server, "0.0.0.0", port);
    evhttp_set_gencb(server, WebApp::incoming, this->routes);
    event_base_dispatch(base);
}
