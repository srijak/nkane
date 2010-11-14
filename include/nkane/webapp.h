#ifndef NKANE_WEBAPP_H
#define NKANE_WEBAPP_H

#include <map>
#include <iostream>

class RouteMapper;

typedef std::map<std::string, std::string> Headers;

class WebApp {
private:
  struct evhttp *server;
  struct event_base *base;
  int port;
  RouteMapper* routes;

public:
  WebApp(RouteMapper* r);
  void run(int port);
  static void incoming(struct evhttp_request *r, void *args);
};

#endif

