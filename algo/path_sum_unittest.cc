#include <gtest/gtest.h>
#include "path_sum.cpp"

class PathSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PathSumTest, Small){
    int a[] = {5, 4, 8, 11, NULL_NODE, 13, 4, 7, 2, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 1};
    VI nums(ASZ(a));
    TreeNode *root(vector2Tree(nums));
    EXPECT_EQ(true, sol.hasPathSum(root, 22));
}
