#include <gtest/gtest.h>
#include "find_minimum_sorted_array.cpp"

class FindMinimumSortedArrayTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(FindMinimumSortedArrayTest, Small){
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArrayTest, Small2){
    int a[] = {4, 5, 6, 7, 0};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.findMin(nums));
}
