#ifndef ROUTE_MAPPER_H
#define ROUTE_MAPPER_H

#include <iostream>
#include <utility>
#include <vector>

#include "nkane/base_controller.h"

class RouteMapper {
private:
  std::vector<std::pair<std::string, BaseController*> > routes;

public:
  RouteMapper& add(const std::string& url, BaseController* controller);
  BaseController* resolve(const std::string& url);

};

#endif
