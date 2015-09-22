#include <gtest/gtest.h>
#include "convert_sorted_binary_tree.cpp"

class ConvertSortedBinaryTreeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ConvertSortedBinaryTreeTest, Small){
    VI nums;
    for (int i = 0;i < 10; ++i) nums.push_back(i);
    TreeNode* root(sol.sortedArrayToBST(nums));
    printTree(root);
}
