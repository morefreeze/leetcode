#include <gtest/gtest.h>
#include "combination_sum3.cpp"

class CombinationSum3Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CombinationSum3Test, Small){
    int z0[] = {1,2,4};
    VVI ans;
    ans.PB(VI(ASZ(z0)));
    EXPECT_EQ(ans, sol.combinationSum3(3, 7));
}
TEST_F(CombinationSum3Test, Small2){
    int z0[] = {1,2,6};
    int z1[] = {1,3,5};
    int z2[] = {2,3,4};
    VVI ans;
    ans.PB(VI(ASZ(z0)));
    ans.PB(VI(ASZ(z1)));
    ans.PB(VI(ASZ(z2)));
    EXPECT_EQ(ans, sol.combinationSum3(3, 9));
}
