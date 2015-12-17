#include <gtest/gtest.h>
#include "stock3.cpp"

class Stock3Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Stock3Test, Small){
    int a[] = {0,3,2,0,4,6,5,11};
    VI nums(ASZ(a));
    EXPECT_EQ(14, sol.maxProfit(nums));
}
TEST_F(Stock3Test, Small2){
    int a[] = {1,2};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.maxProfit(nums));
}
