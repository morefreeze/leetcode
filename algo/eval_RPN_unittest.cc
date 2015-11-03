#include <gtest/gtest.h>
#include "eval_RPN.cpp"

class EvalRPNTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(EvalRPNTest, Small){
    string a[] = {"2", "1", "+", "3", "*"};
    vector<string> tokens(ASZ(a));
    EXPECT_EQ(9, sol.evalRPN(tokens));
}
TEST_F(EvalRPNTest, Small2){
    string a[] = {"4", "13", "5", "/", "+"};
    vector<string> tokens(ASZ(a));
    EXPECT_EQ(6, sol.evalRPN(tokens));
}
