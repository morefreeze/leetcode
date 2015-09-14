#include <gtest/gtest.h>
#include "single_number.cpp"

class SingleNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SingleNumberTest, Small){
    int a[] = {1,2,3,5,3,2,1};
    VI nums(ASZ(a));
    EXPECT_EQ(5, sol.singleNumber(nums));
}
