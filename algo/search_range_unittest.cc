#include <gtest/gtest.h>
#include "search_range.cpp"

class SearchRangeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SearchRangeTest, Small){
    int a[] = {5, 7, 7, 8, 8, 10};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    int z[] = {3,4};
    VI ans(z, z+sizeof(z)/sizeof(z[0]));
    EXPECT_EQ(ans, sol.searchRange(nums, 8));
}
TEST_F(SearchRangeTest, Same){
    int a[] = {8, 8, 8, 8, 8, 8};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    int z[] = {0,5};
    VI ans(z, z+sizeof(z)/sizeof(z[0]));
    EXPECT_EQ(ans, sol.searchRange(nums, 8));
}
TEST_F(SearchRangeTest, NotFound){
    int a[] = {8, 8, 8, 8, 8, 8};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    int z[] = {-1,-1};
    VI ans(z, z+sizeof(z)/sizeof(z[0]));
    EXPECT_EQ(ans, sol.searchRange(nums, 9));
}
TEST_F(SearchRangeTest, NotFound2){
    int a[] = {5, 7, 7, 8, 8};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    int z[] = {-1,-1};
    VI ans(z, z+sizeof(z)/sizeof(z[0]));
    EXPECT_EQ(ans, sol.searchRange(nums, 6));
}
