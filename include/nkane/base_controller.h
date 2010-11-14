#ifndef BASE_CONTROLLER_H_
#define BASE_CONTROLLER_H_

#include "nkane/reply.h"

class BaseController {
protected:
  virtual Reply get_notfound_reply() {
    return Reply::defaultNotFound();
  }
protected:
  bool try_process(struct evhttp_request* request, Reply* reply) {
    return false;
  }

public:
  virtual ~BaseController() {};

  Reply process(struct evhttp_request* r) {
    Reply result;
    if (try_process(r, &result)) {
      return result;
    }
    return this->get_notfound_reply();
  }
};

#endif
