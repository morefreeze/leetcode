#include <gtest/gtest.h>
#include "RSQ2D.cpp"

class RSQ2DTest: public testing::Test{
    protected:
};
TEST_F(RSQ2DTest, Small){
    VVI nums;
    int a0[] = {3, 0, 1, 4, 2};
    nums.PB(VI(ASZ(a0)));
    int a1[] = {5, 6, 3, 2, 1};
    nums.PB(VI(ASZ(a1)));
    int a2[] = {1, 2, 0, 1, 5};
    nums.PB(VI(ASZ(a2)));
    int a3[] = {4, 1, 0, 1, 7};
    nums.PB(VI(ASZ(a3)));
    int a4[] = {1, 0, 3, 0, 5};
    nums.PB(VI(ASZ(a4)));
    NumMatrix sol(nums);
    EXPECT_EQ(8, sol.sumRegion(2, 1, 4, 3));
    EXPECT_EQ(11, sol.sumRegion(1, 1, 2, 2));
    EXPECT_EQ(12, sol.sumRegion(1, 2, 2, 4));
}
