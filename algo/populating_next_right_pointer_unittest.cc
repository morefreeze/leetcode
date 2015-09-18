#include <gtest/gtest.h>
#include "populating_next_right_pointer.cpp"

class PopulatingNextRightPointerTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PopulatingNextRightPointerTest, Small){
    int a[] = {0,1,2,3,4,5,6};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLink(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    EXPECT_EQ(ans, dumpTreeLink(root));
}
TEST_F(PopulatingNextRightPointerTest, Not_Full){
    int a[] = {0,1,2,3,4,5,6,7};
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLink(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    EXPECT_EQ(ans, dumpTreeLink(root));
}
TEST_F(PopulatingNextRightPointerTest, Big){
    int a[123];
    for (int i = 0;i < 123;++i) a[i] = i;
    VI v(ASZ(a));
    TreeLinkNode *root(vector2TreeLink(v));
    sol.connect(root);
    vector< vector<int> > ans(makeTreeLinkAns(v));
    EXPECT_EQ(ans, dumpTreeLink(root));
}
