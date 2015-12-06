#include <gtest/gtest.h>
#include "construct_tree_postorder.cpp"

class ConstructTreePostorderTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ConstructTreePostorderTest, Empty){
    VI post;
    VI inorder;
    EXPECT_EQ(NULL, sol.buildTree(inorder, post));
}
TEST_F(ConstructTreePostorderTest, Small){
    int a[] = {2,3,1,4,5};
    VI inorder(ASZ(a));
    int b[] = {2,1,3,4,5};
    VI post(ASZ(b));
    printTree(sol.buildTree(inorder, post));
}
TEST_F(ConstructTreePostorderTest, Small2){
    int a[] = {1,2};
    VI inorder(ASZ(a));
    int b[] = {2,1};
    VI post(ASZ(b));
    printTree(sol.buildTree(inorder, post));
}
