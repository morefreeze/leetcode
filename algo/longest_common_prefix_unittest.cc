#include <gtest/gtest.h>
#include "longest_common_prefix.cpp"

class LongestCommonPrefixTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(LongestCommonPrefixTest, Small){
    vector<string> vs;
    EXPECT_EQ("", sol.longestCommonPrefix(vs));
    vs.PB(string("a"));
    EXPECT_EQ("a", sol.longestCommonPrefix(vs));
    vs.PB(string("a"));
    vs.PB(string("b"));
    EXPECT_EQ("", sol.longestCommonPrefix(vs));
}
