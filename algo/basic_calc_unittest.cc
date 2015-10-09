#include <gtest/gtest.h>
#include "basic_calc.cpp"

class BasicCalcTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BasicCalcTest, Trim){
    string s("1 + 1");
    sol.trim(s);
    EXPECT_EQ("1+1", s);
}
TEST_F(BasicCalcTest, Trim2){
    string s(" 2-1 + 2 ");
    sol.trim(s);
    EXPECT_EQ("2-1+2", s);
}
TEST_F(BasicCalcTest, Small){
    EXPECT_EQ(2, sol.calculate("1 + 1"));
    EXPECT_EQ(22, sol.calculate(" 2-1 + 21 "));
    EXPECT_EQ(23, sol.calculate("(1+(4+5+2)-3)+(6+8)"));
}
TEST_F(BasicCalcTest, Big){
    EXPECT_EQ(-9721374, sol.calculate("78393+232-9799999"));
}
TEST_F(BasicCalcTest, Zero){
    EXPECT_EQ(0, sol.calculate("0-0+0-0-(0-0+0)-0+(0+0)"));
    EXPECT_EQ(1, sol.calculate("0-0+0-0-(0-1+0)-0+(0+0)"));
}
TEST_F(BasicCalcTest, Parenthes){
    EXPECT_EQ(42, sol.calculate("(42)"));
    EXPECT_EQ(-4, sol.calculate("1-(5)"));
}
