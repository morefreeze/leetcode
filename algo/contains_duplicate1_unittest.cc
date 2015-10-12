#include <gtest/gtest.h>
#include "contains_duplicate1.cpp"

class ContainsDuplicate1Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ContainsDuplicate1Test, SmallFalse){
    int a[] = {1,2,3,4};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.containsDuplicate(nums));
}
TEST_F(ContainsDuplicate1Test, SmallTrue){
    int a[] = {1,2,3,2};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.containsDuplicate(nums));
}
