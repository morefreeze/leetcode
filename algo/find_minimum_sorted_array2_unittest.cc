#include <gtest/gtest.h>
#include "find_minimum_sorted_array2.cpp"

class FindMinimumSortedArray2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(FindMinimumSortedArray2Test, Small){
    int a[] = {4, 5, 6, 7, 0, 1, 2};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Small2){
    int a[] = {7, 0};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Small3){
    int a[] = {2,3,4,0,2,2};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Same){
    int a[] = {2,2,2,2,2,2,2};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Same2){
    int a[] = {10,1,10,10,10};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Same3){
    int a[] = {3,3,1,3};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.findMin(nums));
}
TEST_F(FindMinimumSortedArray2Test, Same4){
    int a[] = {3,3,3,3,3,3,3,3,1,3};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.findMin(nums));
}
