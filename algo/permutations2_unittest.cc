#include <gtest/gtest.h>
#include "permutations2.cpp"

class Permutations2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Permutations2Test, Small){
    int a[] = {1,1,2};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    int z1[] = {1,1,2};
    ans.PB(VI(z1, z1+sizeof(z1)/sizeof(z1[0])));
    int z2[] = {1,2,1};
    ans.PB(VI(z2, z2+sizeof(z2)/sizeof(z2[0])));
    int z3[] = {2,1,1};
    ans.PB(VI(z3, z3+sizeof(z3)/sizeof(z3[0])));
    EXPECT_EQ(ans, sol.permuteUnique(nums));
}
TEST_F(Permutations2Test, Same){
    int a[] = {1,1,1};
    VI nums(a, a+sizeof(a)/sizeof(a[0]));
    VVI ans;
    int z1[] = {1,1,1};
    ans.PB(VI(z1, z1+sizeof(z1)/sizeof(z1[0])));
    EXPECT_EQ(ans, sol.permuteUnique(nums));
}
