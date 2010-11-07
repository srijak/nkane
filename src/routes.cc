#include "nkane/routes.h"
#include "nkane/reply.h"
#include <map>
#include <iostream>
#include <vector>

using namespace std;

Reply Routes::process_get(const string& url, const map<string, string>& headers){

  // SHOULD:
  //   loop through routes setup to call the whatever is in charge 
  //   of handling the current url.

  // CURRENT(for manual testing):
  //vector<string> url_sections = utils::split(url, '/');
  
  cout << "URL:" << url<< endl;
  cout << "Headers:" << endl;

  map<string, string>::const_iterator iter;
  for (iter=headers.begin(); iter != headers.end(); ++iter) {
    cout << "\t"<< iter->first << ": " << iter->second << endl;
  }
 
  Reply r;
  r.set_header("Content-Type", "application/json; charset=UTF8");
  r.append_body("{\"status\": \"ok\"}");
  return r;
}
void Routes::add(const string& url_pattern, const RequestHandler* handler)
{
	route_map.push_back(make_pair(url_pattern, handler));
	
}
