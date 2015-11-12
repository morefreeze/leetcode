#include <gtest/gtest.h>
#include "sqrt.cpp"

class SqrtTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SqrtTest, Small){
    EXPECT_EQ(2, sol.mySqrt(4));
    EXPECT_EQ(2, sol.mySqrt(7));
    EXPECT_EQ(2, sol.mySqrt(8));
    EXPECT_EQ(3, sol.mySqrt(9));
    EXPECT_EQ(3, sol.mySqrt(10));
    EXPECT_EQ(3, sol.mySqrt(11));
    EXPECT_EQ(3, sol.mySqrt(12));
    EXPECT_EQ(3, sol.mySqrt(13));
}
TEST_F(SqrtTest, Small2){
    EXPECT_EQ(123, sol.mySqrt(123*123+2));
}
