#include <gtest/gtest.h>
#include "find_missing_positive.cpp"

class FindMissingPositiveTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(FindMissingPositiveTest, Small){
    int a[] = {1,2,0};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(3, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, Small2){
    int a[] = {3,4,-1,1};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(2, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, Small3){
    int a[] = {3,4,-1,2};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(1, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, NumBigAll){
    int a[] = {0,-1,999,1000};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(1, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, NumBig){
    int a[] = {3,4,999,1};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(2, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, Same){
    int a[] = {1,1};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(2, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, Order){
    int a[] = {0,1,2};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(3, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, RunTime){
    int a[] = {0,2,2,4,0,3,2,4,0};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(1, sol.firstMissingPositive(nums));
}
TEST_F(FindMissingPositiveTest, RunTime2){
    int a[] = {10,9,8,7,6,5,4,3,2,999};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(1, sol.firstMissingPositive(nums));
}

