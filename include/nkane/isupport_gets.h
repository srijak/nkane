#include <iostream>

class Reply;

class ISupportGets {
 public:
  virtual ~ISupportGets(){}
  virtual Reply Get(const std::string& url, const std::map<std::string, std::string>& headers) = 0;
};
