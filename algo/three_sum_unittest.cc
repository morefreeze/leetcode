#include <gtest/gtest.h>
#include "three_sum.cpp"

class ThreeSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ThreeSumTest, Small){
    int a[] = {-1, 0, 1, 2, -1, -4};
    VI nums(a, a+sizeof(a)/sizeof(int));
    vector<VI> ans;
    VI t;
    t.PB(-1); t.PB(-1); t.PB(2);
    ans.PB(t);
    t.clear();
    t.PB(-1); t.PB(0); t.PB(1);
    ans.PB(t);
    EXPECT_EQ(ans, sol.threeSum(nums));
}
