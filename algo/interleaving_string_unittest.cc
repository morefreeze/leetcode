#include <gtest/gtest.h>
#include "interleaving_string.cpp"

class InterleavingStringTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(InterleavingStringTest, Small){
    EXPECT_EQ(true, sol.isInterleave("123", "456", "142563"));
    EXPECT_EQ(true, sol.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    EXPECT_EQ(false, sol.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}
