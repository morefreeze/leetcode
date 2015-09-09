#include <gtest/gtest.h>
#include "h_index.cpp"

class HIndexTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(HIndexTest, Small){
    int a[] = {3, 0, 6, 1, 5};
    VI n(ASZ(a));
    EXPECT_EQ(3, sol.hIndex(n));
}
TEST_F(HIndexTest, Zero){
    int a[] = {0};
    VI n(ASZ(a));
    EXPECT_EQ(0, sol.hIndex(n));
}
TEST_F(HIndexTest, One){
    int a[] = {1, 1};
    VI n(ASZ(a));
    EXPECT_EQ(1, sol.hIndex(n));
}
