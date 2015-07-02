#include <gtest/gtest.h>
#include "merge_k_list.cpp"

class MergeKListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MergeKListTest, Small){
    int a[] = {1,3,5};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {2,4,6};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    vector<ListNode*> vl;
    vl.PB(l1);
    vl.PB(l2);
    int c[] = {1,2,3,4,5,6};
    VI ans(c, c+sizeof(c)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeKLists(vl)));
}
TEST_F(MergeKListTest, Triple){
    int a[] = {1,3};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {2,4};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    int c[] = {5,6};
    ListNode *l3(vector2List(VI(c, c+sizeof(c)/sizeof(int))));
    vector<ListNode*> vl;
    vl.PB(l1);
    vl.PB(l2);
    vl.PB(l3);
    int z[] = {1,2,3,4,5,6};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeKLists(vl)));
}
