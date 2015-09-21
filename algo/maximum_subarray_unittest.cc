#include <gtest/gtest.h>
#include "maximum_subarray.cpp"

class MaximumSubarrayTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaximumSubarrayTest, Small){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    VI nums(ASZ(a));
    EXPECT_EQ(6, sol.maxSubArray(nums));
}
TEST_F(MaximumSubarrayTest, Negative){
    int a[] = {-3, -2, -1};
    VI nums(ASZ(a));
    EXPECT_EQ(-1, sol.maxSubArray(nums));
}
