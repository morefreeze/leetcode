#include <gtest/gtest.h>
#include "add_digits.cpp"

class AddDigitsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(AddDigitsTest, Small){
    EXPECT_EQ(0, sol.addDigits(0));
    EXPECT_EQ(1, sol.addDigits(1));
    EXPECT_EQ(9, sol.addDigits(9));
    EXPECT_EQ(2, sol.addDigits(38));
}
