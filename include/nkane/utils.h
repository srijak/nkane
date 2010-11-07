#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

namespace utils
{
using namespace std;

vector<string> split(const string &s, const char delim)
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
}

#endif
