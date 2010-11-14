#include <gtest/gtest.h>
#include <nkane/route_mapper.h>
#include <nkane/base_controller.h>

class MockController: public BaseController{

};

TEST (RouteMapperTest, no_match_returns_NULL) {
  RouteMapper rm;
  EXPECT_EQ(NULL, rm.resolve("whatever"));
}

TEST (RouteMapperTest, exact_match_returns_correct_controller) {
  RouteMapper rm;
  MockController* m = new MockController();
  rm.add("/a/b", m);
  EXPECT_EQ(m, rm.resolve("/a/b"));
}


TEST (RouteMapperTest, exact_match_glob_returns_correct_controller) {
  RouteMapper rm;
  MockController* m = new MockController();
  rm.add("/a/*", m);
  EXPECT_EQ(m, rm.resolve("/a/b"));
}

TEST (RouteMapperTest, multiple_match_returns_first_controller) {
  RouteMapper rm;
  MockController* m0 = new MockController();
  MockController* m1 = new MockController();

  rm.add("/a/b", m0);
  rm.add("/a/b", m1);

  EXPECT_EQ(m0, rm.resolve("/a/b"));
}

TEST (RouteMapperTest, multiple_match_glob_returns_first_controller) {
  RouteMapper rm;
  MockController* m0 = new MockController();
  MockController* m1 = new MockController();

  rm.add("/a/*", m0);
  rm.add("/a/b", m1);

  EXPECT_EQ(m0, rm.resolve("/a/b"));
}
