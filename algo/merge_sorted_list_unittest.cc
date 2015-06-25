#include <gtest/gtest.h>
#include "merge_sorted_list.cpp"
#include "list_helper.h"

class MergeSortedListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MergeSortedListTest, Null){
    EXPECT_EQ(NULL, sol.mergeTwoLists(NULL, NULL));
}
TEST_F(MergeSortedListTest, Small){
    int a[] = {1,3,5};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {2,4,6};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    int c[] = {1,2,3,4,5,6};
    VI ans(c, c+sizeof(c)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeTwoLists(l1, l2)));
}
TEST_F(MergeSortedListTest, DiffSize){
    int a[] = {1,3,5};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {0,2,4,6};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    int c[] = {0,1,2,3,4,5,6};
    VI ans(c, c+sizeof(c)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeTwoLists(l1, l2)));
}
TEST_F(MergeSortedListTest, Repeat){
    int a[] = {1,1,3,3,3,5};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {0,2,3,4,4,5,5};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    int c[] = {0,1,1,2,3,3,3,3,4,4,5,5,5};
    VI ans(c, c+sizeof(c)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeTwoLists(l1, l2)));
}
TEST_F(MergeSortedListTest, T1){
    int a[] = {1,3,4};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int b[] = {0};
    ListNode *l2(vector2List(VI(b, b+sizeof(b)/sizeof(int))));
    int c[] = {0,1,3,4};
    VI ans(c, c+sizeof(c)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.mergeTwoLists(l1, l2)));
}
