#include <gtest/gtest.h>
#include "h_index2.cpp"

class HIndex2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(HIndex2Test, Small){
    int a[] = {0, 1, 3, 5, 6};
    VI n(ASZ(a));
    EXPECT_EQ(3, sol.hIndex(n));
}
TEST_F(HIndex2Test, Zero){
    int a[] = {0};
    VI n(ASZ(a));
    EXPECT_EQ(0, sol.hIndex(n));
}
TEST_F(HIndex2Test, One){
    int a[] = {1, 1};
    VI n(ASZ(a));
    EXPECT_EQ(1, sol.hIndex(n));
}
