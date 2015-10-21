#include <gtest/gtest.h>
#include "basic_calc2.cpp"

class BasicCalc2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BasicCalc2Test, Small){
    EXPECT_EQ(7, sol.calculate("3+2*2"));
    EXPECT_EQ(1, sol.calculate("3/2"));
    EXPECT_EQ(5, sol.calculate("3+5/2"));
}
TEST_F(BasicCalc2Test, Parenthes){
    EXPECT_EQ(18, sol.calculate("3*(4+2)"));
    EXPECT_EQ(18, sol.calculate("3*((4+2/3)+2)"));
    EXPECT_EQ(-4, sol.calculate("1-(5/1)"));
}
