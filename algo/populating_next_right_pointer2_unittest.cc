#include <gtest/gtest.h>
#include "populating_next_right_pointer2.cpp"

class PopulatingNextRightPointer2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PopulatingNextRightPointer2Test, Small){
    int a[] = {1,2,3,4,5,NULL_NODE,7};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLink(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    EXPECT_EQ(ans, dumpTreeLink(root));
}
TEST_F(PopulatingNextRightPointer2Test, Small2){
    int a[] = {1,2,3,4,NULL_NODE,6,7,8,NULL_NODE,NULL_NODE,NULL_NODE,12,NULL_NODE,NULL_NODE,15};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLink(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    EXPECT_EQ(ans, dumpTreeLink(root));
}
TEST_F(PopulatingNextRightPointer2Test, Small3){
    int a[] = {1,NULL_NODE,-9,NULL_NODE,8,4,-2};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLinkLT(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    printTreeLink(root);
}
TEST_F(PopulatingNextRightPointer2Test, Big){
    int a[] = {1,NULL_NODE,-9,NULL_NODE,8,4,-2,NULL_NODE,NULL_NODE,-3,NULL_NODE,-5,NULL_NODE,NULL_NODE,-6,-4,-9,NULL_NODE,NULL_NODE,6};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLinkLT(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    printTreeLink(root);
}
