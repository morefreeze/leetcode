#include <gtest/gtest.h>
#include "combination_sum.cpp"

class CombinationSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CombinationSumTest, Small){
    int a[] = {2,3,6,7};
    VI num(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    int z0[] = {7};
    ans.PB(VI(z0, z0+sizeof(z0)/sizeof(z0[0])));
    int z1[] = {2,2,3};
    ans.PB(VI(z1, z1+sizeof(z1)/sizeof(z1[0])));
    EXPECT_EQ(ans, sol.combinationSum(num, 7));
}
TEST_F(CombinationSumTest, Big){
    int a[] = {2,3,6,7,6,4,10,53,21,19,42,33,68,77};
    VI num(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    EXPECT_NE(ans, sol.combinationSum(num, 99));
}
