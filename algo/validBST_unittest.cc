#include <gtest/gtest.h>
#include "validBST.cpp"

class ValidBSTTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ValidBSTTest, Small){
    int a[] = {10,5, 15,NULL_NODE, NULL_NODE, 6, 20};
    TreeNode *root(vector2Tree(vector<int>(ASZ(a))));
    EXPECT_EQ(false, sol.isValidBST(root));
}
