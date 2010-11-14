#include <nkane/nkane.h>

#include "main_controller.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  RouteMapper* r = new RouteMapper();

  (*r).add("/blah/blah", new MainController())
  .add("hwat>", new MainController());

  WebApp* app = new WebApp(r);
  app->run(5537);

  return 0;
}
