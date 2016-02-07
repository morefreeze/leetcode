#include <gtest/gtest.h>
#include "num_1bits.cpp"

class Num1bitsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Num1bitsTest, Small){
    EXPECT_EQ(3, sol.hammingWeight(11));
}
