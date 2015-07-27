#include <gtest/gtest.h>
#include "trap_rain.cpp"

class TrapRainTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(TrapRainTest, Small){
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    VI h(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(6, sol.trap(h));
}
TEST_F(TrapRainTest, Small2){
    int a[] = {3,2,3,4,3,1,2,1,5,4,5};
    VI h(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(11, sol.trap(h));
}
TEST_F(TrapRainTest, Zero){
    int a[] = {3,4,99,10000,10,2,0};
    VI h(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(0, sol.trap(h));
}
