#include <gtest/gtest.h>
#include "binary_tree_max_sum.cpp"

class BinaryTreeMaxSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BinaryTreeMaxSumTest, Small){
    int a[] = {2, 3, -1, -3, -2, 1, 1, NULL_NODE, NULL_NODE, NULL_NODE, NULL_NODE, 3, NULL_NODE, NULL_NODE, -2};
    TreeNode *root(vector2Tree(vector<int>(ASZ(a))));
    EXPECT_EQ(8, sol.maxPathSum(root));
}
TEST_F(BinaryTreeMaxSumTest, One){
    TreeNode root(-3);
    EXPECT_EQ(-3, sol.maxPathSum(&root));
}
TEST_F(BinaryTreeMaxSumTest, Small2){
    TreeNode root(-2), r1(1);
    root.right = &r1;
    EXPECT_EQ(1, sol.maxPathSum(&root));
}
TEST_F(BinaryTreeMaxSumTest, Big){
    int a[] = {5,4,8,11,NULL_NODE,13,4,7,2,NULL_NODE,NULL_NODE,NULL_NODE,NULL_NODE,NULL_NODE,1};
    TreeNode *root(vector2Tree(vector<int>(ASZ(a))));
    EXPECT_EQ(48, sol.maxPathSum(root));
}
