#include <gtest/gtest.h>
#include "single_number2.cpp"

class SingleNumber2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SingleNumber2Test, Small){
    int a[] = {-1,-2,-3,-4,-3,-2,-1,-2,-1,-3};
    VI nums(ASZ(a));
    EXPECT_EQ(-4, sol.singleNumber(nums));
}
