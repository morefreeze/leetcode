#include <gtest/gtest.h>
#include "ugly_num2.cpp"

class UglyNum2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UglyNum2Test, Small){
    EXPECT_EQ(12, sol.nthUglyNumber(10));
}
TEST_F(UglyNum2Test, Big){
    EXPECT_EQ(51200000, sol.nthUglyNumber(1000));
    EXPECT_EQ(2066242608, sol.nthUglyNumber(1685));
}
