#include <gtest/gtest.h>
#include "burst_balloons.cpp"

class BurstBalloonsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(BurstBalloonsTest, Small){
    int a[] = {3,1,5,8};
    VI nums(ASZ(a));
    EXPECT_EQ(167, sol.maxCoins(nums));
}
