#include <gtest/gtest.h>
#include "stock_cooldown.cpp"

class StockCooldownTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(StockCooldownTest, Small){
    int a[] = {1,2,3,0,2};
    VI nums(ASZ(a));
    EXPECT_EQ(3, sol.maxProfit(nums));
}
TEST_F(StockCooldownTest, Small2){
    int a[] = {0,1,0,4,0,2};
    VI nums(ASZ(a));
    EXPECT_EQ(4, sol.maxProfit(nums));
}
