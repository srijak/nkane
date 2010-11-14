#ifndef REPLY_H
#define REPLY_H

#include "nkane/typedefs.h"
#include "nkane/httpstatuscode.h"

class Reply {
protected:
  Headers headers;
  std::string body;
	enum HttpStatusCode status;

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
	enum HttpStatusCode get_status(){
		return this->status;
	}
  void set_status(enum HttpStatusCode status_code){
		status = status_code;
	}
  static Reply defaultNotFound() {
    Reply r;
		r.set_status(Not_Found);
    r.append_body("NOT FOUND");
    return r;
  }

};

#endif
