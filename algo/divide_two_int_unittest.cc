#include <gtest/gtest.h>
#include "divide_two_int.cpp"

class DivideTwoIntTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(DivideTwoIntTest, Small){
    EXPECT_EQ(41, sol.divide(123, 3));
    EXPECT_EQ(123, sol.divide(123, 1));
    EXPECT_EQ(0, sol.divide(5, 7));
}
TEST_F(DivideTwoIntTest, Overflow){
    EXPECT_EQ(2147483647, sol.divide(-2147483648, -1));
    EXPECT_EQ(0, sol.divide(2147483647, -2147483648));
    EXPECT_EQ(1, sol.divide(-2147483648, -2147483648));
    EXPECT_EQ(-2147483648, sol.divide(-2147483648, 1));
}
