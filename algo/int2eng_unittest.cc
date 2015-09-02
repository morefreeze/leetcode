#include <gtest/gtest.h>
#include "int2eng.cpp"

class Int2engTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Int2engTest, Small){
    EXPECT_EQ("One Hundred Twenty Three", sol.numberToWords(123));
    EXPECT_EQ("Twelve Thousand Three Hundred Forty Five", sol.numberToWords(12345));
    EXPECT_EQ("One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven", sol.numberToWords(1234567));
}
TEST_F(Int2engTest, Fixed){
    EXPECT_EQ("Zero", sol.numberToWords(0));
    EXPECT_EQ("One", sol.numberToWords(1));
    EXPECT_EQ("Five", sol.numberToWords(5));
    EXPECT_EQ("Nine", sol.numberToWords(9));
    EXPECT_EQ("Twelve", sol.numberToWords(12));
    EXPECT_EQ("Fifteen", sol.numberToWords(15));
    EXPECT_EQ("Eighteen", sol.numberToWords(18));
    EXPECT_EQ("Twenty", sol.numberToWords(20));
    EXPECT_EQ("Forty", sol.numberToWords(40));
    EXPECT_EQ("Eighty", sol.numberToWords(80));
}
TEST_F(Int2engTest, Zero){
    EXPECT_EQ("One Hundred Two", sol.numberToWords(102));
    EXPECT_EQ("One Hundred Two Thousand", sol.numberToWords(102000));
    EXPECT_EQ("One Hundred Thousand Two", sol.numberToWords(100002));
    EXPECT_EQ("One Million Two Hundred", sol.numberToWords(1000200));
    EXPECT_EQ("One Billion Two", sol.numberToWords(1000000002));
    EXPECT_EQ("One Billion Two Hundred", sol.numberToWords(1000000200));
}
TEST_F(Int2engTest, Big){
    EXPECT_EQ("One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety", sol.numberToWords(1234567890));
}
