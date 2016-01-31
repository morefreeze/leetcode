#include <gtest/gtest.h>
#include "happy_number.cpp"

class HappyNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(HappyNumberTest, Small){
    EXPECT_FALSE(sol.isHappy(14));
    EXPECT_FALSE(sol.isHappy(15));
    EXPECT_FALSE(sol.isHappy(16));
    EXPECT_FALSE(sol.isHappy(17));
    EXPECT_FALSE(sol.isHappy(18));
    EXPECT_TRUE(sol.isHappy(19));
}
