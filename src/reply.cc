#include "nkane/reply.h"

#include <iostream>
using namespace std;

void Reply::set_header(const string& key, const string& val){
  headers[key] = val;
}

string Reply::get_header(const string& key){
  map<string, string>::iterator itr = headers.find(key);
  if (itr != headers.end()){
    return itr->second;
  }else{
    return "";
  }
}

void Reply::append_body(const string& str){
  body += str;
}

string Reply::get_body(){
  return body;
}

map<string, string> Reply::get_headers(){
  return headers;
}
