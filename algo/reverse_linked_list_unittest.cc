#include <gtest/gtest.h>
#include "reverse_linked_list.cpp"

class ReverseLinkedListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ReverseLinkedListTest, Small){
    int a[] = {1,2,3,4};
    VI nums(ASZ(a));
    int z[] = {4,3,2,1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseList(vector2List(nums))));
}
TEST_F(ReverseLinkedListTest, Small2){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {5,4,3,2,1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    EXPECT_EQ(ans, list2Vector(sol.reverseList(vector2List(nums))));
}
