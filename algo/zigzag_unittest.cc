#include <gtest/gtest.h>
#include "zigzag.cpp"

TEST(Zigzag, Small){
    Solution sol;
    EXPECT_EQ("06c157bd248aeg39f", sol.convert("0123456789abcdefg", 4));
    EXPECT_EQ("a", sol.convert("a", 1));
}
