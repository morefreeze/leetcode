#include <gtest/gtest.h>
#include "longest_valid_parentheses.cpp"

class LongestValidParenthesesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(LongestValidParenthesesTest, Small){
    EXPECT_EQ(4, sol.longestValidParentheses(")()())"));
    EXPECT_EQ(2, sol.longestValidParentheses("(()"));
    EXPECT_EQ(2, sol.longestValidParentheses("((((()"));
    EXPECT_EQ(4, sol.longestValidParentheses("(())))()()"));
}
TEST_F(LongestValidParenthesesTest, Spe){
    EXPECT_EQ(2, sol.longestValidParentheses("()(()"));
}
