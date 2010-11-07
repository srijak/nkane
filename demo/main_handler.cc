#include <nkane/nkane.h>
#include <nkane/utils.h>

#include "main_handler.h"

#include <map>
#include <iostream>
#include <vector>

using namespace std;

Reply MainHandler::Get(const string& url, const Headers& headers){

  // SHOULD:
  //   loop through routes setup to call the whatever is in charge 
  //   of handling the current url.

  // CURRENT(for manual testing):
  //vector<string> url_sections = RequestHandler::split(url, '/');
  
  cout << "URL:" << url<< endl;
  cout << "Headers:" << endl;

  Headers::const_iterator iter;
  for (iter=headers.begin(); iter != headers.end(); ++iter) {
    cout << "\t"<< iter->first << ": " << iter->second << endl;
  }
 
  Reply r;
  r.set_header("Content-Type", "application/json; charset=UTF8");
  r.append_body("{\"status\": \"ok\"}");
  return r;
}
