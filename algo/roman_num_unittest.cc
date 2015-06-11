#include <gtest/gtest.h>
#include "roman_num.cpp"

class RomanNumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RomanNumTest, Small){
    EXPECT_EQ("I", sol.intToRoman(1));
    EXPECT_EQ("IV", sol.intToRoman(4));
    EXPECT_EQ("VII", sol.intToRoman(7));
    EXPECT_EQ("VIII", sol.intToRoman(8));
    EXPECT_EQ("IX", sol.intToRoman(9));
}
TEST_F(RomanNumTest, Medium){
    EXPECT_EQ("XLIX", sol.intToRoman(49));
    EXPECT_EQ("L", sol.intToRoman(50));
    EXPECT_EQ("LXVIII", sol.intToRoman(68));
    EXPECT_EQ("LXXXVIII", sol.intToRoman(88));
    EXPECT_EQ("XCIX", sol.intToRoman(99));
}
TEST_F(RomanNumTest, Tens){
    EXPECT_EQ("M", sol.intToRoman(1000));
    EXPECT_EQ("DCCLX", sol.intToRoman(760));
    EXPECT_EQ("CMXC", sol.intToRoman(990));
    EXPECT_EQ("MMCMXC", sol.intToRoman(2990));
}
TEST_F(RomanNumTest, Big){
    EXPECT_EQ("MCMLIV", sol.intToRoman(1954));
    EXPECT_EQ("MCMXC", sol.intToRoman(1990));
    EXPECT_EQ("MMXIV", sol.intToRoman(2014));
}
