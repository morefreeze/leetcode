#include <gtest/gtest.h>
#include "minimum_window_substring.cpp"

class MinimumWindowSubstringTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MinimumWindowSubstringTest, Small){
    EXPECT_EQ("BANC", sol.minWindow("ADOBECODEBANC", "ABC"));
}
