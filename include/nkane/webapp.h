#ifndef NKANE_WEBAPP_H
#define NKANE_WEBAPP_H

#include <map>
#include <iostream>

class Routes;
typedef std::map<std::string, std::string> Headers;

class WebApp
{
    struct evhttp *server;
    struct event_base *base;
    int port;
		Routes* routes;	
private:
    static std::string get_header(struct evhttp_request *r, const char* key);
    static std::map<std::string, std::string> get_headers_map(const struct evkeyvalq *headers);

public:
    WebApp(int port, Routes* r);
    void run();	
    static void incoming(struct evhttp_request *r, void *args);
};

#endif

