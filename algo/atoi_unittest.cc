#include <gtest/gtest.h>
#include "atoi.cpp"

class AtoiTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(AtoiTest, Small){
    EXPECT_EQ(123, sol.myAtoi("123"));
    EXPECT_EQ(-123, sol.myAtoi("-123"));
}
TEST_F(AtoiTest, Invalid){
    EXPECT_EQ(0, sol.myAtoi("    "));
    EXPECT_EQ(0, sol.myAtoi("    -"));
    EXPECT_EQ(123, sol.myAtoi("    123  "));
    EXPECT_EQ(-123, sol.myAtoi("    -123  "));
    EXPECT_EQ(-123, sol.myAtoi("    -123-  "));
    EXPECT_EQ(0, sol.myAtoi(" b11228552307"));
}
TEST_F(AtoiTest, Overflow){
    EXPECT_EQ(2147483647, sol.myAtoi("    2147483647  "));
    EXPECT_EQ(2147483647, sol.myAtoi("    2147483648  "));
    EXPECT_EQ(2147483647, sol.myAtoi("    9999983648  "));
    EXPECT_EQ(-2147483647, sol.myAtoi("   -2147483647  "));
    EXPECT_EQ(-2147483648, sol.myAtoi("   -2147483648  "));
    EXPECT_EQ(-2147483648, sol.myAtoi("   -9999483648  "));
}
TEST_F(AtoiTest, Sign){
    EXPECT_EQ(0, sol.myAtoi("+-2"));
    EXPECT_EQ(2, sol.myAtoi("+2"));
}

