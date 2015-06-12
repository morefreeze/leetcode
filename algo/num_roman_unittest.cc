#include <gtest/gtest.h>
#include "num_roman.cpp"

class NumRomanTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NumRomanTest, Small){
    EXPECT_EQ(20, sol.romanToInt("XX"));
    EXPECT_EQ(9, sol.romanToInt("IX"));
    EXPECT_EQ(8, sol.romanToInt("VIII"));
    EXPECT_EQ(18, sol.romanToInt("XVIII"));
}
TEST_F(NumRomanTest, Medium){
    EXPECT_EQ(49, sol.romanToInt("XLIX"));
    EXPECT_EQ(50, sol.romanToInt("L"));
    EXPECT_EQ(68, sol.romanToInt("LXVIII"));
    EXPECT_EQ(88, sol.romanToInt("LXXXVIII"));
    EXPECT_EQ(99, sol.romanToInt("XCIX"));
}
TEST_F(NumRomanTest, Tens){
    EXPECT_EQ(1000, sol.romanToInt("M"));
    EXPECT_EQ(760, sol.romanToInt("DCCLX"));
    EXPECT_EQ(990, sol.romanToInt("CMXC"));
    EXPECT_EQ(2990, sol.romanToInt("MMCMXC"));
}
TEST_F(NumRomanTest, Big){
    EXPECT_EQ(1954, sol.romanToInt("MCMLIV"));
    EXPECT_EQ(1990, sol.romanToInt("MCMXC"));
    EXPECT_EQ(2014, sol.romanToInt("MMXIV"));
}
