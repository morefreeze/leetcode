#include <gtest/gtest.h>
#include "num_digit1.cpp"

class NumDigit1Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NumDigit1Test, Small){
    EXPECT_EQ(1, sol.countDigitOne(7));
    EXPECT_EQ(2, sol.countDigitOne(10));
    EXPECT_EQ(6, sol.countDigitOne(13));
    EXPECT_EQ(12, sol.countDigitOne(20));
}
TEST_F(NumDigit1Test, Medium){
    EXPECT_EQ(338, sol.countDigitOne(1024));
}
TEST_F(NumDigit1Test, Big){
    EXPECT_EQ(1218511431, sol.countDigitOne(1147483647));
}
