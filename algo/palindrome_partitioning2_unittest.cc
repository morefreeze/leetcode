#include <gtest/gtest.h>
#include "palindrome_partitioning2.cpp"

class PalindromePartitioning2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PalindromePartitioning2Test, Small){
    EXPECT_EQ(0, sol.minCut("bb"));
    EXPECT_EQ(1, sol.minCut("bba"));
    EXPECT_EQ(3, sol.minCut("ababbbabbaba"));
}
