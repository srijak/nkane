#ifndef ROUTES_H
#define ROUTES_H

#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

class Reply;
class RequestHandler;

class Routes
{
 protected:
  vector<pair<string, RequestHandler* > > routes;
  
 public:
  Reply process_get(const string& url, const std::map<string, string>& headers);
  void add(const string& url_patter, RequestHandler* handler);
};

#endif

