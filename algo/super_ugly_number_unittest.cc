#include <gtest/gtest.h>
#include "super_ugly_number.cpp"

class SuperUglyNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SuperUglyNumberTest, Small){
    int a[] = {2,7,13,19};
    VI nums(ASZ(a));
    EXPECT_EQ(32, sol.nthSuperUglyNumber(12, nums));
}
TEST_F(SuperUglyNumberTest, Medium){
    int a[] = {2,7,13,19};
    VI nums(ASZ(a));
    EXPECT_EQ(85489664, sol.nthSuperUglyNumber(1000, nums));
}
TEST_F(SuperUglyNumberTest, Big){
    int a[] = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    VI nums(ASZ(a));
    EXPECT_EQ(1092889481, sol.nthSuperUglyNumber(100000, nums));
}
