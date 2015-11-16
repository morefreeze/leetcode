#include <gtest/gtest.h>
#include "RSQ.cpp"

class RSQTest: public testing::Test{
    protected:
};
TEST_F(RSQTest, Small){
    int a[] = {-2, 0, 3, -5, 2, -1};
    VI nums(ASZ(a));
    NumArray sol(nums);
    EXPECT_EQ(1, sol.sumRange(0, 2));
    EXPECT_EQ(-1, sol.sumRange(2, 5));
    EXPECT_EQ(-3, sol.sumRange(0, 5));
}
