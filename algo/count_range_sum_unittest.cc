#include <gtest/gtest.h>
#include "count_range_sum.cpp"

class CountRangeSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CountRangeSumTest, Small){
    int a[] = {-2, 5, -1};
    VI nums(ASZ(a));
    EXPECT_EQ(3, sol.countRangeSum(nums, -2, 2));
}
