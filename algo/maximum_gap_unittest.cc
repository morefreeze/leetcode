#include <gtest/gtest.h>
#include "maximum_gap.cpp"

class MaximumGapTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaximumGapTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
