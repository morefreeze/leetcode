#include <gtest/gtest.h>
#include "binary_tree_right.cpp"

class BinaryTreeRightTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BinaryTreeRightTest, Small){
    int a[] = {1, 2, 3, NULL_NODE, 5, NULL_NODE, 4};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    int z[] = {1, 3, 4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.rightSideView(root));
}
TEST_F(BinaryTreeRightTest, Small2){
    int a[] = {1, 2, 3, 4};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    int z[] = {1, 3, 4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.rightSideView(root));
}
TEST_F(BinaryTreeRightTest, Null){
    VI ans;
    EXPECT_EQ(ans, sol.rightSideView(NULL));
}
TEST_F(BinaryTreeRightTest, Left){
    int a[] = {1, 2, NULL_NODE, 5, NULL_NODE, NULL_NODE, NULL_NODE, 7};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    int z[] = {1, 2, 5, 7};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.rightSideView(root));
}
