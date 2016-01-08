#include <gtest/gtest.h>
#include "recover_BST.cpp"

class RecoverBSTTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RecoverBSTTest, Small){
    int a[] = {1,2,3};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    sol.recoverTree(root);
    midOrder(root);
    EXPECT_TRUE(checkBST(root));
}
TEST_F(RecoverBSTTest, Small2){
    //              4
    //            /    \
    //           2      8
    //         /  \    /
    //       (5)   3   6
    //                /  \
    //               (1)  7
    int a[] = {4,2,8,5,3,6,NULL_NODE,NULL_NODE,NULL_NODE,NULL_NODE,NULL_NODE,1,7};
    TreeNode *root(vector2Tree(VI(ASZ(a))));
    sol.recoverTree(root);
    midOrder(root);
    EXPECT_TRUE(checkBST(root));
}
TEST_F(RecoverBSTTest, SmallLT){
    //              2
    //            /    \
    //           (6)    4
    //                 /  \
    //                3    (1)
    //                     /
    //                    5
    // just test vector2TreeLT
    int a[] = {2,6,4,NULL_NODE,NULL_NODE,3,1,NULL_NODE,NULL_NODE,5};
    TreeNode *root(vector2TreeLT(VI(ASZ(a))));
    midOrder(root);
    cout << endl;
    sol.recoverTree(root);
    midOrder(root);
    EXPECT_TRUE(checkBST(root));
}
