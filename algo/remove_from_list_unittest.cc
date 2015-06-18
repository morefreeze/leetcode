#include <gtest/gtest.h>
#include "remove_from_list.cpp"

class RemoveFromListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveFromListTest, Small){
    int a[] = {1,2,3,4,5};
    VI t(a, a+sizeof(a)/sizeof(int));
    ListNode *head(sol.vector2List(t));
    int b[] = {1,2,3,5};
    VI ans(b, b+sizeof(b)/sizeof(int));
    EXPECT_EQ(ans, sol.list2Vector(sol.removeNthFromEnd(head, 2)));
}
TEST_F(RemoveFromListTest, Bound){
    int a[] = {1,2,3,4,5};
    VI t(a, a+sizeof(a)/sizeof(int));
    ListNode *head(sol.vector2List(t));
    int b[] = {2,3,4,5};
    VI ans(b, b+sizeof(b)/sizeof(int));
    EXPECT_EQ(ans, sol.list2Vector(sol.removeNthFromEnd(head, 5)));
}
TEST_F(RemoveFromListTest, Bound2){
    int a[] = {1,2,3,4,5};
    VI t(a, a+sizeof(a)/sizeof(int));
    ListNode *head(sol.vector2List(t));
    int b[] = {1,2,3,4};
    VI ans(b, b+sizeof(b)/sizeof(int));
    EXPECT_EQ(ans, sol.list2Vector(sol.removeNthFromEnd(head, 1)));
}
