#include <gtest/gtest.h>
#include "missing_num.cpp"

class MissingNumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MissingNumTest, Small){
    int a[] = {0,2,3,4,1,7,6};
    VI nums(ASZ(a));
    EXPECT_EQ(5, sol.missingNumber(nums));
}
TEST_F(MissingNumTest, Last){
    int a[] = {0,2,3,4,1,5,6};
    VI nums(ASZ(a));
    EXPECT_EQ(7, sol.missingNumber(nums));
}
