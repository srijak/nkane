#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <nkane/nkane.h>

class GetHandler: public RequestHandler, public ISupportGets{
public: 
  virtual ~GetHandler() {}
  virtual Reply Get(const std::string& url, const Headers& headers){}
};
class MockHandler : public GetHandler {
public:
  MOCK_METHOD2(Get, Reply(const string&, const Headers&));	
};

using ::testing::Return;         
using ::testing::NiceMock;

TEST (RoutesTest, add_single_route) {
  NiceMock<MockHandler> handler0;
  Reply ret;
  ret.append_body("GET HANDLED");
  string url0 = "/a/b";
  Headers headers;

  Routes r;	
  r.add(url0, &handler0);

  ON_CALL(handler0, Get(url0, headers))  
    .WillByDefault(Return(ret));
  
  EXPECT_EQ(ret.get_body(), r.process_get(url0, headers).get_body());
}

TEST (RoutesTest, add_route_identified_correctly) {
  NiceMock<MockHandler> handler0;
  NiceMock<MockHandler> handler1;
  Reply ret;
  ret.append_body("GET HANDLED");
  string url0 = "/a/b";
  string url1 = "/b/a";

  Headers headers;

  Routes r;	
  r.add(url1, &handler1);
  r.add(url0, &handler0);
  
  ON_CALL(handler0, Get(url0, headers))  
    .WillByDefault(Return(ret));
  
  EXPECT_EQ(ret.get_body(), r.process_get(url0, headers).get_body());
}

TEST (RoutesTest, first_match_returned) {
  NiceMock<MockHandler> handler0;
  NiceMock<MockHandler> handler1;
  Reply ret;
  ret.append_body("GET HANDLED");

  string url0 = "/a/b";
  string url1 = "/a/b";

  Headers headers;

  Routes r;	
  r.add(url0, &handler0);
  r.add(url0, &handler1);
  
  ON_CALL(handler0, Get(url0, headers))  
    .WillByDefault(Return(ret));
  
  EXPECT_EQ(ret.get_body(), r.process_get(url0, headers).get_body());
}
