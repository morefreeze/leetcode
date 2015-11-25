#include <gtest/gtest.h>
#include "path_sum2.cpp"

class PathSum2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PathSum2Test, Small){
    int a[] = {5, 4, 8, 11, NULL_NODE, 13, 4, 7, 2, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 5, 1};
    VI nums(ASZ(a));
    TreeNode *root(vector2Tree(nums));
    int z0[] = {5,4,11,2};
    int z1[] = {5,8,4,5};
    VVI ans;
    ans.PB(VI(ASZ(z0)));
    ans.PB(VI(ASZ(z1)));
    EXPECT_EQ(ans, sol.pathSum(root, 22));
}
