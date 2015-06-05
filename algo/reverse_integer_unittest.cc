#include <gtest/gtest.h>
#include "reverse_integer.cpp"

TEST(REVERSE_INTEGER, Small){
    Solution sol;
    EXPECT_EQ(321, sol.reverse(123));
    EXPECT_EQ(-321, sol.reverse(-123));
}
TEST(REVERSE_INTEGER, Overflow){
    Solution sol;
    EXPECT_EQ(0, sol.reverse(1000000003));
    EXPECT_EQ(0, sol.reverse(-1000000009));
}
TEST(REVERSE_INTEGER, Big){
    Solution sol;
    EXPECT_EQ(1, sol.reverse(1000000000));
    EXPECT_EQ(2000000001, sol.reverse(1000000002));
    EXPECT_EQ(-2000000001, sol.reverse(-1000000002));
}
