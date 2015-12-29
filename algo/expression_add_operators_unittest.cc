#include <gtest/gtest.h>
#include "expression_add_operators.cpp"

class ExpressionAddOperatorsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ExpressionAddOperatorsTest, Small){
    string z[] = {"1+2+3", "1*2*3"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("123", 6));
}
TEST_F(ExpressionAddOperatorsTest, Small2){
    string z[] = {"2+3*2", "2*3+2"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("232", 8));
}
TEST_F(ExpressionAddOperatorsTest, Small3){
    string z[] = {"1*0+5","10-5"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("105", 5));
}
TEST_F(ExpressionAddOperatorsTest, Small4){
    string z[] = {"0+0", "0-0", "0*0"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("00", 0));
}
TEST_F(ExpressionAddOperatorsTest, Small5){
    string z[] = {};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("3456237490", 9191));
}
TEST_F(ExpressionAddOperatorsTest, Empty){
    string z[] = {};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("", 5));
}
TEST_F(ExpressionAddOperatorsTest, Big){
    string z[] = {};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.addOperators("2147483648", -2147483648));
}
