#include "nkane/route_mapper.h"
#include "nkane/base_controller.h"
#include <fnmatch.h>

using namespace std;

RouteMapper&
RouteMapper::add(const string& url, BaseController* controller) {
  this->routes.push_back(pair<string, BaseController*> (url, controller));
  return *this;
}

BaseController*
RouteMapper::resolve(const std::string& url) {

  vector<pair<string, BaseController*> >::iterator itr;
  for (itr = routes.begin(); itr < routes.end(); ++itr) {
    if (fnmatch(itr->first.c_str(), url.c_str(), FNM_PATHNAME) == 0) {
      return itr->second;
    }
  }
  return NULL;
}
