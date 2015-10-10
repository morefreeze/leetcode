#include <gtest/gtest.h>
#include "maximum_product_subarray.cpp"

class MaximumProductSubarrayTest: public testing::Test{
    protected:
        Solution sol;
};
// helper function test
TEST_F(MaximumProductSubarrayTest, Odd){
    int a[] = {-1,-2,-3};
    VI nums(ASZ(a));
    EXPECT_EQ(6, sol.maxProductNoZero(nums, 0, SZ(nums)));
}
TEST_F(MaximumProductSubarrayTest, Odd2){
    int a[] = {-3,-2,-1};
    VI nums(ASZ(a));
    EXPECT_EQ(6, sol.maxProductNoZero(nums, 0, SZ(nums)));
}
TEST_F(MaximumProductSubarrayTest, Odd3){
    int a[] = {2,-3,-3,-1,-4,-2,3};
    VI nums(ASZ(a));
    EXPECT_EQ(72, sol.maxProductNoZero(nums, 0, SZ(nums)));
}
TEST_F(MaximumProductSubarrayTest, Even){
    int a[] = {-1,-2,-3,-4};
    VI nums(ASZ(a));
    EXPECT_EQ(24, sol.maxProductNoZero(nums, 0, SZ(nums)));
}

// solution function test
TEST_F(MaximumProductSubarrayTest, Zero){
    int a[] = {-1,-2,0,-3,-4};
    VI nums(ASZ(a));
    EXPECT_EQ(12, sol.maxProduct(nums));
}
TEST_F(MaximumProductSubarrayTest, Zero2){
    int a[] = {-2,0,-3};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.maxProduct(nums));
}
TEST_F(MaximumProductSubarrayTest, Zero3){
    int a[] = {1,2,0,3,-4};
    VI nums(ASZ(a));
    EXPECT_EQ(3, sol.maxProduct(nums));
}
TEST_F(MaximumProductSubarrayTest, Zero4){
    int a[] = {-1,0,-4};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.maxProduct(nums));
}
TEST_F(MaximumProductSubarrayTest, Zero5){
    int a[] = {-1,0,-2,0,-3,0,-4};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.maxProduct(nums));
}
TEST_F(MaximumProductSubarrayTest, One){
    int a[] = {-42};
    VI nums(ASZ(a));
    EXPECT_EQ(-42, sol.maxProduct(nums));
}
