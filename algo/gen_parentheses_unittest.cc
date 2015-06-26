#include <gtest/gtest.h>
#include "gen_parentheses.cpp"

class GenParenthesesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(GenParenthesesTest, Small){
    string a[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
    vector<string> ans(a, a+5);
    EXPECT_EQ(ans, sol.generateParenthesis(3));
}
