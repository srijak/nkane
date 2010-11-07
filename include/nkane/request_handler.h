#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

#include <iostream>
#include <vector>

class RequestHandler
{
	 //Base class for all requests.
	 //will provide helper function, filter aplication, model binding etcs
	 public: 	
			std::vector<std::string> split(const std::string& str, const char delim);
};

#endif

