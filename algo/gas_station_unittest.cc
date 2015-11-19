#include <gtest/gtest.h>
#include "gas_station.cpp"

class GasStationTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(GasStationTest, Small){
    int a[] = {3,-7,2,-1,3};
    VI nums(ASZ(a));
    EXPECT_EQ(2, sol.calc(nums));
}
TEST_F(GasStationTest, Small2){
    int a[] = {-9,8,-9,9,9,7,-9,2,-8};
    VI nums(ASZ(a));
    EXPECT_EQ(3, sol.calc(nums));
}
TEST_F(GasStationTest, Small3){
    int a[] = {-1,0};
    VI nums(ASZ(a));
    EXPECT_EQ(-1, sol.calc(nums));
}
TEST_F(GasStationTest, One){
    int a[] = {0};
    VI nums(ASZ(a));
    EXPECT_EQ(0, sol.calc(nums));
}
TEST_F(GasStationTest, CounterClock){
    int a[] = {6,1,4,3,5};
    int b[] = {3,8,2,4,2};
    VI gas(ASZ(a));
    VI cost(ASZ(b));
    EXPECT_EQ(2, sol.canCompleteCircuit(gas, cost));
}
