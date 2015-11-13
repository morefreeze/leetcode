#include <gtest/gtest.h>
#include "minimum_subarray_sum.cpp"

class MinimumSubarraySumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MinimumSubarraySumTest, Small){
    int a[] = {2,3,1,2,4,3};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.minSubArrayLen(7, nums));
    EXPECT_EQ(1, sol.minSubArrayLen(4, nums));
    EXPECT_EQ(2, sol.minSubArrayLen(6, nums));
    EXPECT_EQ(3, sol.minSubArrayLen(9, nums));
}
TEST_F(MinimumSubarraySumTest, Small2){
    int a[] = {9,8,7,6,5,4,3,2,1};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.minSubArrayLen(12, nums));
}
TEST_F(MinimumSubarraySumTest, Small3){
    int a[] = {1,2,3,4,5,6,7,8,9};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.minSubArrayLen(12, nums));
}
TEST_F(MinimumSubarraySumTest, None){
    int a[] = {1,2,3,4,5,6,7,8,9};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.minSubArrayLen(46, nums));
}
