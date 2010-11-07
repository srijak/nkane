#ifndef MAIN_HANDLER_H
#define MAIN_HANDLER_H

#include <iostream>
#include <map>

using namespace std;

class Reply;

class MainHandler: public RequestHandler, public ISupportGets 
{
public:
  virtual Reply Get(const string& url, const Headers& headers);
};

#endif

