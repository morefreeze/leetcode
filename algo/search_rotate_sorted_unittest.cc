#include <gtest/gtest.h>
#include "search_rotate_sorted.cpp"

class SearchRotateSortedTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SearchRotateSortedTest, Small){
    int a[] = {4,5,6,7,0,1,2};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(0, sol.search(nums, 4));
}
TEST_F(SearchRotateSortedTest, Small2){
    int a[] = {4,5,6,7,0,1,2};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(3, sol.search(nums, 7));
}
TEST_F(SearchRotateSortedTest, Small3){
    int a[] = {4,5,6,7,0,};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(4, sol.search(nums, 0));
}
TEST_F(SearchRotateSortedTest, Small4){
    int a[] = {4,5,6,7,0,1,999};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(6, sol.search(nums, 999));
}
TEST_F(SearchRotateSortedTest, NotFound){
    int a[] = {4,};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(-1, sol.search(nums, 7));
}
TEST_F(SearchRotateSortedTest, NotFound2){
    int a[] = {4,5,6,7,0,1,2};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(-1, sol.search(nums, 3));
}
TEST_F(SearchRotateSortedTest, NotFound3){
    int a[] = {4,5,6,7,0,1,2};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(-1, sol.search(nums, 10));
}
