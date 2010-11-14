#ifndef INVALID_HTTP_STATUS_CODE_EXCEPTION_H
#define INVALID_HTTP_STATUS_CODE_EXCEPTION_H

#include <stdexcept>

class InvalidHttpStatusCodeException : public std::runtime_error {
  public:
		InvalidHttpStatusCodeException::InvalidHttpStatusCodeException (): runtime_error( "Invalid Http status code") {}
};

#endif
