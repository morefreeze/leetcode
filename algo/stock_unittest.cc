#include <gtest/gtest.h>
#include "stock.cpp"

class StockTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(StockTest, Small){
    int a[] = {4,3,6,9,8,7,2,1};
    VI nums(ASZ(a));
    EXPECT_EQ(6, sol.maxProfit(nums));
}
