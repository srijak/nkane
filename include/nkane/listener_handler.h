#ifndef LISTENER_HANDLER_H
#define LISTENER_HANDLER_H

#include <iostream>
#include <map>

using namespace std;

class Reply;

class ListenerHandler
{
public:
  Reply process_get(const string& url, const std::map<string, string>& headers);
  
};

#endif

