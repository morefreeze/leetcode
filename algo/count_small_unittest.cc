#include <gtest/gtest.h>
#include "count_small.cpp"

class CountSmallTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CountSmallTest, Small){
    int a[] = {5,2,6,1};
    VI nums(ASZ(a));
    int z[] = {2, 1, 1, 0};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.countSmaller(nums));
}
