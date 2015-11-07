#include <gtest/gtest.h>
#include "sort_list.cpp"

class SortListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SortListTest, Small){
    int a[] = {4,5,9,6,1,6,8,7,2};
    ListNode *head(sol.sortList(vector2List(VI(ASZ(a)))));
    int z[] = {1,2,4,5,6,6,7,8,9};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(SortListTest, One){
    int a[] = {4};
    ListNode *head(sol.sortList(vector2List(VI(ASZ(a)))));
    int z[] = {4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(SortListTest, Two){
    int a[] = {4,1};
    ListNode *head(sol.sortList(vector2List(VI(ASZ(a)))));
    int z[] = {1,4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(head));
}
