#include <gtest/gtest.h>
#include "decode_ways.cpp"

class DecodeWaysTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(DecodeWaysTest, Small){
    EXPECT_EQ(2, sol.numDecodings("12"));
    EXPECT_EQ(3, sol.numDecodings("1234"));
    EXPECT_EQ(5, sol.numDecodings("1111"));
}
TEST_F(DecodeWaysTest, Zero){
    EXPECT_EQ(1, sol.numDecodings("10"));
    EXPECT_EQ(0, sol.numDecodings("012"));
    EXPECT_EQ(0, sol.numDecodings("30"));
    EXPECT_EQ(1, sol.numDecodings("110"));
    EXPECT_EQ(1, sol.numDecodings("1101"));
}
TEST_F(DecodeWaysTest, Big){
    EXPECT_EQ(4, sol.numDecodings("10874982754378912738947821072874892014"));
}
