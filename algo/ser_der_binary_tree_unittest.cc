#include <gtest/gtest.h>
#include "ser_der_binary_tree.cpp"

class SerDerBinaryTreeTest: public testing::Test{
    protected:
        Codec codec;
};
TEST_F(SerDerBinaryTreeTest, Small){
    int a[] = {1,2,3,NULL_NODE, NULL_NODE, 4,5};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    string ans(codec.serialize(root));
    TreeNode *root2(codec.deserialize(ans));
    string ans2(codec.serialize(root2));
    EXPECT_EQ(ans, ans2);
}
