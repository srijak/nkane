#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

namespace utils {

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
