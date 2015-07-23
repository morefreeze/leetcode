#include <gtest/gtest.h>
#include "combination_sum2.cpp"

class CombinationSum2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CombinationSum2Test, Small){
    int a[] = {10,1,2,7,6,1,5};
    VI num(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    int z0[] = {1,7};
    ans.PB(VI(z0, z0+sizeof(z0)/sizeof(z0[0])));
    int z1[] = {2,6};
    ans.PB(VI(z1, z1+sizeof(z1)/sizeof(z1[0])));
    int z2[] = {1,1,6};
    ans.PB(VI(z2, z2+sizeof(z2)/sizeof(z2[0])));
    int z3[] = {1,2,5};
    ans.PB(VI(z3, z3+sizeof(z3)/sizeof(z3[0])));
    EXPECT_EQ(ans, sol.combinationSum2(num, 8));
}
