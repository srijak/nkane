#include "nkane/request_handler.h"

#include <iostream>
#include <sstream>

using namespace std;

vector<string> RequestHandler::split(const string &s, const char delim)
{
    vector<string> elems;
    stringstream ss(s);
    string item;

    while(getline(ss, item, delim)) {
        if (item.length() > 0) {
            elems.push_back(item);
        }
    }
    return elems;
}

