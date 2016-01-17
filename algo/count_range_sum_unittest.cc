#include <gtest/gtest.h>
#include "count_range_sum.cpp"

class CountRangeSumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CountRangeSumTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
