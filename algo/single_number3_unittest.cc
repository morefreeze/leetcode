#include <gtest/gtest.h>
#include "single_number3.cpp"

class SingleNumber3Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SingleNumber3Test, Small){
    int a[] = {1,2,3,2,5,1};
    VI nums(ASZ(a));
    int z[] = {3,5};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.singleNumber(nums));
}
