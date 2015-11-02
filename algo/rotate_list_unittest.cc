#include <gtest/gtest.h>
#include "rotate_list.cpp"

class RotateListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RotateListTest, Small){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    int z[] = {4,5,1,2,3};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    head = sol.rotateRight(head, 2);
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(RotateListTest, One){
    int a[] = {1};
    VI nums(ASZ(a));
    int z[] = {1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    head = sol.rotateRight(head, 1);
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(RotateListTest, Zero){
    int a[] = {};
    VI nums(ASZ(a));
    int z[] = {};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    head = sol.rotateRight(head, 0);
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(RotateListTest, Great){
    int a[] = {1,2};
    VI nums(ASZ(a));
    int z[] = {2,1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    head = sol.rotateRight(head, 3);
    EXPECT_EQ(ans, list2Vector(head));
}
TEST_F(RotateListTest, Great2){
    int a[] = {1,2,3};
    VI nums(ASZ(a));
    int z[] = {2,3,1};
    VI ans(ASZ(z));
    ListNode *head(vector2List(nums));
    head = sol.rotateRight(head, 2000000000);
    EXPECT_EQ(ans, list2Vector(head));
}
