#include <gtest/gtest.h>
#include "super_ugly_number.cpp"

class SuperUglyNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SuperUglyNumberTest, Small){
    int a[] = {2,7,13,19};
    VI nums(ASZ(a));
    EXPECT_EQ(32, sol.nthSuperUglyNumber(12, nums));
}
