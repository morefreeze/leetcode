#include <gtest/gtest.h>
#include "pow.cpp"

class PowTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PowTest, Small){
    EXPECT_EQ(1024, sol.myPow(2, 10));
}
TEST_F(PowTest, Negative){
    EXPECT_EQ(0.0009765625, sol.myPow(2, -10));
}
TEST_F(PowTest, Big){
    EXPECT_EQ(1, sol.myPow(1, -2147483648));
}
