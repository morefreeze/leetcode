#include <gtest/gtest.h>
#include "sliding_window.cpp"

class SlidingWindowTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SlidingWindowTest, Small){
    int a[] = {1,3,-1,-3,5,3,6,7};
    VI nums(ASZ(a));
    int z[] = {3,3,5,5,6,7};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxSlidingWindow(nums, 3));
}
TEST_F(SlidingWindowTest, Small2){
    int a[] = {7,2,4};
    VI nums(ASZ(a));
    int z[] = {7,4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxSlidingWindow(nums, 2));
}
TEST_F(SlidingWindowTest, Zero){
    int a[] = {};
    VI nums(ASZ(a));
    int z[] = {};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxSlidingWindow(nums, 0));
}
