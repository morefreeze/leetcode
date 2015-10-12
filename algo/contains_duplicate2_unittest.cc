#include <gtest/gtest.h>
#include "contains_duplicate2.cpp"

class ContainsDuplicate2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ContainsDuplicate2Test, SmallFalse){
    int a[] = {1,2,3,2};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.containsNearbyDuplicate(nums,1));
}
TEST_F(ContainsDuplicate2Test, SmallTrue){
    int a[] = {1,2,3,2};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.containsNearbyDuplicate(nums,2));
}
