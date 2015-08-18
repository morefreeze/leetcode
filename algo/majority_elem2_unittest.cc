#include <gtest/gtest.h>
#include "majority_elem2.cpp"

class MajorityElem2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MajorityElem2Test, Small){
    int a[] = {3, 4, 1, 2, 2, 1, 5, 1};
    VI nums(ASZ(a));
    int z[] = {1};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
TEST_F(MajorityElem2Test, GreatOneThird){
    int a[] = {3, 4, 1, 2, 2, 1, 5, 1, 2};
    VI nums(ASZ(a));
    int z[] = {};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
TEST_F(MajorityElem2Test, GreatOneThird2){
    int a[] = {1, 2, 3};
    VI nums(ASZ(a));
    int z[] = {};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
TEST_F(MajorityElem2Test, None){
    int a[] = {3, 4, 1, 2, 2, 1, 5, 1, 2, 3};
    VI nums(ASZ(a));
    int z[] = {};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
TEST_F(MajorityElem2Test, OnlyOne){
    int a[] = {3};
    VI nums(ASZ(a));
    int z[] = {3};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
TEST_F(MajorityElem2Test, Less3){
    int a[] = {2, 2};
    VI nums(ASZ(a));
    int z[] = {2};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.majorityElement(nums));
}
