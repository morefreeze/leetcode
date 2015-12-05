#include <gtest/gtest.h>
#include "reverse_linked_list2.cpp"

class ReverseLinkedList2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ReverseLinkedList2Test, Small){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {1,4,3,2,5};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseBetween(vector2List(nums), 2, 4)));
}
TEST_F(ReverseLinkedList2Test, Reverse){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {5,4,3,2,1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseBetween(vector2List(nums), 1, 5)));
}
TEST_F(ReverseLinkedList2Test, Out){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {1,5,4,3,2};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseBetween(vector2List(nums), 2, 6)));
}
TEST_F(ReverseLinkedList2Test, Out2){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {1,2,3,4,5};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseBetween(vector2List(nums), 5, 7)));
}
