#include <gtest/gtest.h>
#include "remove_dup_sorted_list.cpp"

class RemoveDupSortedListTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveDupSortedListTest, Small){
    int a[] = {1,1,2,2,4,5};
    VI nums(ASZ(a));
    int z[] = {1,2,4,5};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(sol.deleteDuplicates(vector2List(nums))));
}
TEST_F(RemoveDupSortedListTest, None){
    int a[] = {1,1,2,2,3,3,3,5,5};
    VI nums(ASZ(a));
    int z[] = {1,2,3,5};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(sol.deleteDuplicates(vector2List(nums))));
}
TEST_F(RemoveDupSortedListTest, Distinct){
    int a[] = {1,2,3,4,5,6,7,8,9};
    VI nums(ASZ(a));
    int z[] = {1,2,3,4,5,6,7,8,9};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, list2Vector(sol.deleteDuplicates(vector2List(nums))));
}
