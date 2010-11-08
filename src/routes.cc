#include "nkane/routes.h"
#include "nkane/reply.h"
#include "nkane/request_handler.h"
#include "nkane/isupport_gets.h"
#include <map>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

Reply Routes::process_get(const string& url, const map<string, string>& headers){
  
  for (vector<pair<string, RequestHandler*> >::iterator it = routes.begin(); it < routes.end(); ++it)
    {
      if (it->first.compare(url) == 0){
	ISupportGets* g = dynamic_cast<ISupportGets*>(it->second);
	if (g){
	  return g->Get(url, headers);
	}
      }
    }
  Reply error;
  error.append_body("{\"status\":\"url or method not found\" }");
  return error;
}
void Routes::add(const string& url_pattern, RequestHandler* handler)
{
  routes.push_back(make_pair(url_pattern, handler));
}

