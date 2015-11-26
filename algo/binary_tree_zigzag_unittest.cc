#include <gtest/gtest.h>
#include "binary_tree_zigzag.cpp"

class BinaryTreeZigzagTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BinaryTreeZigzagTest, Small){
    int a[] = {3,9,20,NULL_NODE,NULL_NODE,15,7};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    int z0[] = {3};
    int z1[] = {20,9};
    int z2[] = {15,7};
    VVI ans;
    ans.PB(VI(ASZ(z0)));
    ans.PB(VI(ASZ(z1)));
    ans.PB(VI(ASZ(z2)));
    EXPECT_EQ(ans, sol.zigzagLevelOrder(root));
}
