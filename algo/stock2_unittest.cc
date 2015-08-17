#include <gtest/gtest.h>
#include "stock2.cpp"

class Stock2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Stock2Test, Small){
    int a[] = {3, 7, 5, 4, 3, 2, 6, 9};
    VI nums(ASZ(a));
    EXPECT_EQ(11, sol.maxProfit(nums));
}
TEST_F(Stock2Test, Small2){
    int a[] = {3, 7, 5, 4, 3, 2, 1};
    VI nums(ASZ(a));
    EXPECT_EQ(4, sol.maxProfit(nums));
}
TEST_F(Stock2Test, Reverse){
    int a[] = {7, 5, 4, 3, 2, 1};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.maxProfit(nums));
}
