#include <evhttp.h>
#include <sys/queue.h>

#include "nkane/webapp.h"
#include "nkane/route_mapper.h"
#include "nkane/typedefs.h"

using namespace std;

WebApp::WebApp (RouteMapper* routes) {
  this->routes = routes;
}

void
WebApp::incoming(struct evhttp_request* r, void* args) {
  string url = evhttp_request_get_uri(r);

  BaseController* c =  ((RouteMapper*) args)->resolve(url);
  Reply result;

  if (c != NULL) {
    result = c->process(r);
  } else {
    result = Reply::defaultNotFound();
  }

  struct evbuffer* buffer = evbuffer_new();
  struct evkeyvalq* headers = evhttp_request_get_output_headers(r);

  Headers h = result.get_headers();
  for (Headers::iterator itr = h.begin(); itr != h.end(); ++itr) {
    evhttp_add_header(headers, itr->first.c_str(), itr->second.c_str());
  }

  evbuffer_add_printf(buffer, "%s", result.get_body().c_str());

  evhttp_send_reply(r, HTTP_OK, "OK", buffer);
  evbuffer_free(buffer);
}

void
WebApp::run(int port) {
  this->port = port;
  cout <<"Starting on port:"<< port << endl;

  base = event_base_new();
  server = evhttp_new(base);

  evhttp_bind_socket(server, "0.0.0.0", port);
  evhttp_set_gencb(server, WebApp::incoming, this->routes);
  event_base_dispatch(base);
}
