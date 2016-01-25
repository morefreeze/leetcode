#include <gtest/gtest.h>
#include "find_duplicate_number.cpp"

class FindDuplicateNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(FindDuplicateNumberTest, Small){
    int a[] = {1,2,2,2,4};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.findDuplicate(nums));
}
TEST_F(FindDuplicateNumberTest, Small2){
    int a[] = {2,1,1};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.findDuplicate(nums));
}
TEST_F(FindDuplicateNumberTest, Small3){
    int a[] = {1,3,4,2,2};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.findDuplicate(nums));
}
TEST_F(FindDuplicateNumberTest, Small4){
    int a[] = {1,3,4,2,1};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.findDuplicate(nums));
}
