#include "nkane/listener.h"
#include "nkane/listener_handler.h"

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ListenerHandler *h = new ListenerHandler();
    Listener *x = new Listener(5537, h);
    x->run();

    return 0;
}
