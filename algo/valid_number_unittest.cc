#include <gtest/gtest.h>
#include "valid_number.cpp"

class ValidNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ValidNumberTest, Small){
    EXPECT_EQ(true, sol.isNumber("0"));
    EXPECT_EQ(true, sol.isNumber(" 0.1 "));
    EXPECT_EQ(false, sol.isNumber("abc"));
    EXPECT_EQ(false, sol.isNumber("1 a"));
    EXPECT_EQ(false, sol.isNumber(""));
    EXPECT_EQ(false, sol.isNumber("   "));
    EXPECT_EQ(false, sol.isNumber("  . "));
}
TEST_F(ValidNumberTest, Int){
    EXPECT_EQ(true, sol.isNumber("2"));
    EXPECT_EQ(true, sol.isNumber("42"));
    EXPECT_EQ(true, sol.isNumber("042"));
    EXPECT_EQ(true, sol.isNumber("0"));
    EXPECT_EQ(true, sol.isNumber("-0"));
    EXPECT_EQ(true, sol.isNumber("-02"));
    EXPECT_EQ(true, sol.isNumber("-42"));
}
TEST_F(ValidNumberTest, Float){
    EXPECT_EQ(false, sol.isNumber("i.34"));
    EXPECT_EQ(true, sol.isNumber("12.34"));
    EXPECT_EQ(true, sol.isNumber("-12.34"));
    EXPECT_EQ(true, sol.isNumber(".12345"));
    EXPECT_EQ(false, sol.isNumber("12.-34"));
    EXPECT_EQ(false, sol.isNumber("-12.-34"));
    EXPECT_EQ(false, sol.isNumber("12.-3.4"));
    EXPECT_EQ(false, sol.isNumber("12.-34.-5"));
}
TEST_F(ValidNumberTest, E){
    EXPECT_EQ(true, sol.isNumber("2e10"));
    EXPECT_EQ(true, sol.isNumber("2.e10"));
    EXPECT_EQ(true, sol.isNumber(".2e10"));
    EXPECT_EQ(true, sol.isNumber("2e0"));
    EXPECT_EQ(true, sol.isNumber("2e-0"));
    EXPECT_EQ(true, sol.isNumber("2e-02"));
    EXPECT_EQ(true, sol.isNumber("2e02"));
    EXPECT_EQ(true, sol.isNumber("42e2"));
    EXPECT_EQ(true, sol.isNumber("42.e2"));
    EXPECT_EQ(false, sol.isNumber("  .e10"));
    EXPECT_EQ(false, sol.isNumber("  e10"));
    EXPECT_EQ(false, sol.isNumber("-e10"));
}
TEST_F(ValidNumberTest, Sign){
    EXPECT_EQ(true, sol.isNumber("+42"));
    EXPECT_EQ(true, sol.isNumber("+12.34"));
    EXPECT_EQ(false, sol.isNumber("+12.+34"));
    EXPECT_EQ(true, sol.isNumber("+.2"));
    EXPECT_EQ(false, sol.isNumber("+."));
}
