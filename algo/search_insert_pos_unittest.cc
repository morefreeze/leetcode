#include <gtest/gtest.h>
#include "search_insert_pos.cpp"

class SearchInsertPosTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SearchInsertPosTest, Small){
    int a[] = {1,3,5,6};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(2, sol.searchInsert(nums, 5));
}
TEST_F(SearchInsertPosTest, Small2){
    int a[] = {1,3,5,6};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(1, sol.searchInsert(nums, 2));
}
TEST_F(SearchInsertPosTest, Small3){
    int a[] = {1,3,5,6};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(4, sol.searchInsert(nums, 7));
}
TEST_F(SearchInsertPosTest, Small4){
    int a[] = {1,3,5,6};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(0, sol.searchInsert(nums, 0));
}
