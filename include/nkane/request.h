#ifndef REQUEST_H
#define REQUEST_H

#include
#include "nkane/typedefs.h"
#include <iostream>

class Request {
private:
  Headers headers;
  std::string body;
public:
  Request
  Headers get_headers() {
    return this->headers;
  }
  void set_headers(const Headers& headers) {
    this->headers = headers;
  }

  void set_body(const std::string& str) {
    this->body = str;
  }
  std::string get_body() {
    return this->body;
  }

};
#endif
