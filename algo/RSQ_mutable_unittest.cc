#include <gtest/gtest.h>
#include "RSQ_mutable.cpp"

class RSQMutableTest: public testing::Test{
    protected:
};
TEST_F(RSQMutableTest, None){
    int a[] = {};
    VI nums(ASZ(a));
    NumArray sol(nums);
    EXPECT_EQ(0, sol.sumRange(0,2));
}
TEST_F(RSQMutableTest, Small){
    int a[] = {1,3,5};
    VI nums(ASZ(a));
    NumArray sol(nums);
    EXPECT_EQ(9, sol.sumRange(0,2));
    sol.update(1,2);
    EXPECT_EQ(8, sol.sumRange(0,2));
    EXPECT_EQ(7, sol.sumRange(1,2));
}
