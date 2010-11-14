#include <gtest/gtest.h>
#include <nkane/reply.h>

TEST (ReplyTest, get_default_reply) {
	Reply r = Reply::defaultNotFound();
	EXPECT_EQ("NOT FOUND", r.get_body());
	EXPECT_EQ(404, r.get_status());
}
