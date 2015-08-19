#include <gtest/gtest.h>
#include "binary_tree_iterator.cpp"

class BinaryTreeIteratorTest: public testing::Test{
    protected:
        BSTIterator sol;
};
TEST_F(BinaryTreeIteratorTest, Small){
    int a[] = {6, 2, 7, NULL_NODE, 4, NULL_NODE, 9, NULL_NODE, NULL_NODE, 3, 5, NULL_NODE, NULL_NODE, 8};
    TreeNode *root(vector2Tree(vector<int>(ASZ(a))));
    int z[] = {2, 3,4,5,6,7,8,9};
    VI ans(ASZ(z));
    VI exc;
    sol = BSTIterator(root);
    while(sol.hasNext()){
        exc.PB(sol.next());
        //cout << "get " << exc[SZ(exc)-1] << endl;
    }
    EXPECT_EQ(ans, exc);
}
TEST_F(BinaryTreeIteratorTest, OneRoot){
    int a[] = {7};
    TreeNode *root(vector2Tree(vector<int>(ASZ(a))));
    int z[] = {7};
    VI ans(ASZ(z));
    VI exc;
    sol = BSTIterator(root);
    while(sol.hasNext()){
        exc.PB(sol.next());
    }
    EXPECT_EQ(ans, exc);
}
TEST_F(BinaryTreeIteratorTest, None){
    sol = BSTIterator(NULL);
    VI ans, exc;
    while(sol.hasNext()){
        exc.PB(sol.next());
    }
    EXPECT_EQ(ans, exc);
}
