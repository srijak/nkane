#ifndef REPLY_H
#define REPLY_H

#include <map>
#include <iostream>

class Reply {
 private:
  std::map<std::string, std::string> headers;
  std::string body;
 public:
  void set_header(const std::string& key, const std::string& val);
  std::string get_header(const std::string& key);
  void append_body(const std::string& str); 
  std::string get_body();
  std::map<std::string, std::string> get_headers();
};

#endif
