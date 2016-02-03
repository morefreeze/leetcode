#include <gtest/gtest.h>
#include "coin_change.cpp"

class CoinChangeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CoinChangeTest, Small){
    int a[] = {1,2,5};
    VI nums(ASZ(a));
    EXPECT_EQ(3, sol.coinChange(nums, 11));
}
TEST_F(CoinChangeTest, Small2){
    int a[] = {2};
    VI nums(ASZ(a));
    EXPECT_EQ(-1, sol.coinChange(nums, 3));
}
TEST_F(CoinChangeTest, Small3){
    int a[] = {1,2};
    VI nums(ASZ(a));
    EXPECT_EQ(1, sol.coinChange(nums, 1));
}
