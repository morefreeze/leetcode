#include <gtest/gtest.h>
#include "ugly_num.cpp"

class UglyNumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UglyNumTest, Small){
    EXPECT_EQ(false, sol.isUgly(14));
    EXPECT_EQ(false, sol.isUgly(0));
}
