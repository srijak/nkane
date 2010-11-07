#include <nkane/nkane.h>
#include "main_handler.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
		Routes* r = new Routes();
//		r->add("/blah/blah", new MainHandler());

		WebApp* app = new WebApp(5537, r);

		app->run();

    return 0;
}
