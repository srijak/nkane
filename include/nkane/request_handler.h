#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

class RequestHandler
{
 public:
  virtual ~RequestHandler(){}
  //Base class for all requests.
  //will provide helper function, filter aplication, model binding etcs
};

#endif

