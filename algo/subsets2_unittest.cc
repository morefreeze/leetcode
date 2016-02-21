#include <gtest/gtest.h>
#include "subsets2.cpp"

class Subsets2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Subsets2Test, Small){
    int a[] = {1,2,3};
    VI nums(ASZ(a));
    VVI ans;
    ans.PB(VI());
    int z0[] = { 3 };
    ans.PB(VI(ASZ(z0)));
    int z1[] = { 2 };
    ans.PB(VI(ASZ(z1)));
    int z2[] = { 2, 3 };
    ans.PB(VI(ASZ(z2)));
    int z3[] = { 1 };
    ans.PB(VI(ASZ(z3)));
    int z4[] = { 1, 3 };
    ans.PB(VI(ASZ(z4)));
    int z5[] = { 1, 2 };
    ans.PB(VI(ASZ(z5)));
    int z6[] = { 1, 2, 3 };
    ans.PB(VI(ASZ(z6)));
    EXPECT_EQ(ans, sol.subsetsWithDup(nums));
}
TEST_F(Subsets2Test, Duplicate){
    int a[] = {0,0,0};
    VI nums(ASZ(a));
    VVI ans;
    ans.PB(VI());
    int z0[] = {0};
    ans.PB(VI(ASZ(z0)));
    int z1[] = {0,0};
    ans.PB(VI(ASZ(z1)));
    int z2[] = {0,0,0};
    ans.PB(VI(ASZ(z2)));
    EXPECT_EQ(ans, sol.subsetsWithDup(nums));
}
