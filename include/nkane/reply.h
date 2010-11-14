#ifndef REPLY_H
#define REPLY_H

#include "nkane/typedefs.h"

class Reply {
protected:
  Headers headers;
  std::string body;

public:
  Headers get_headers() {
    return this->headers;
  }
  std::string get_body() {
    return this->body;
  }
  void append_body(std::string str) {
    this->body.append(str);
  }
  static Reply defaultNotFound() {
    Reply r;
    r.append_body("NOT FOUND");
    return r;
  }

};

#endif
