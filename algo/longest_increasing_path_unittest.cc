#include <gtest/gtest.h>
#include "longest_increasing_path.cpp"

class LongestIncreasingPathTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(LongestIncreasingPathTest, Small){
    VVI nums;
    int a0[] = {9,9,4};
    nums.PB(VI(ASZ(a0)));
    int a1[] = {6,6,8};
    nums.PB(VI(ASZ(a1)));
    int a2[] = {2,1,1};
    nums.PB(VI(ASZ(a2)));
    EXPECT_EQ(4, sol.longestIncreasingPath(nums));
}
TEST_F(LongestIncreasingPathTest, Small2){
    VVI nums;
    int a0[] = {3,4,5};
    nums.PB(VI(ASZ(a0)));
    int a1[] = {3,2,6};
    nums.PB(VI(ASZ(a1)));
    int a2[] = {2,2,1};
    nums.PB(VI(ASZ(a2)));
    EXPECT_EQ(4, sol.longestIncreasingPath(nums));
}
TEST_F(LongestIncreasingPathTest, Same){
    VVI nums;
    int a0[] = {1,1,1,1};
    nums.PB(VI(ASZ(a0)));
    int a1[] = {1,1,1,1};
    nums.PB(VI(ASZ(a1)));
    int a2[] = {1,1,1,1};
    nums.PB(VI(ASZ(a2)));
    EXPECT_EQ(1, sol.longestIncreasingPath(nums));
}
