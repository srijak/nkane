#ifndef LISTENER_H
#define LISTENER_H

#include <map>
#include <iostream>

class ListenerHandler;

class Listener
{
    struct evhttp *server;
    struct event_base *base;
    int port;
    ListenerHandler* handler;

private:
    static std::string get_header(struct evhttp_request *r, const char* key);
    static std::map<std::string, std::string> get_headers_map(const struct evkeyvalq *headers);

public:
    Listener(int port, ListenerHandler* handler);
    void run();
    static void incoming(struct evhttp_request *r, void *args);
};

#endif

