#include <gtest/gtest.h>
#include "permutations.cpp"

class PermutationsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PermutationsTest, Small){
    int a[] = {2,1,3};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    int z1[] = {1,2,3};
    ans.PB(VI(z1, z1+sizeof(z1)/sizeof(z1[0])));
    int z2[] = {1,3,2};
    ans.PB(VI(z2, z2+sizeof(z2)/sizeof(z2[0])));
    int z3[] = {2,1,3};
    ans.PB(VI(z3, z3+sizeof(z3)/sizeof(z3[0])));
    int z4[] = {2,3,1};
    ans.PB(VI(z4, z4+sizeof(z4)/sizeof(z4[0])));
    int z5[] = {3,1,2};
    ans.PB(VI(z5, z5+sizeof(z5)/sizeof(z5[0])));
    int z6[] = {3,2,1};
    ans.PB(VI(z6, z6+sizeof(z6)/sizeof(z6[0])));
    EXPECT_EQ(ans, sol.permute(nums));
}
