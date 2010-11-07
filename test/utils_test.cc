#include <gtest/gtest.h>
#include "utils.h"

using namespace std;

TEST (UtilsTest, split_empty_string) {
  EXPECT_EQ(0, utils::split("",'/').size());
}
TEST (UtilsTest, split_string_with_just_delimiter) {
  EXPECT_EQ(0, utils::split("/",'/').size());
}
TEST (UtilsTest, split_empty_entries_are_ignored) {
  EXPECT_EQ(2, utils::split("/aword//anotherword/////",'/').size());
}
