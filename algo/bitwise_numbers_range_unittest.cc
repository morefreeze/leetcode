#include <gtest/gtest.h>
#include "bitwise_numbers_range.cpp"

class BitwiseNumbersRangeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BitwiseNumbersRangeTest, Small){
    EXPECT_EQ(4, sol.rangeBitwiseAnd(5,7));
    EXPECT_EQ(0, sol.rangeBitwiseAnd(1,3));
}
TEST_F(BitwiseNumbersRangeTest, Big){
    EXPECT_EQ(0, sol.rangeBitwiseAnd(20000,2147483647));
}
