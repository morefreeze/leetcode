#include <gtest/gtest.h>
#include "additive_number.cpp"

class AdditiveNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(AdditiveNumberTest, Check){
    EXPECT_EQ("3", sol.check("1", "2", "3"));
    EXPECT_EQ("12", sol.check("3", "9", "12"));
    EXPECT_EQ("1009", sol.check("999", "10", "1009"));
    EXPECT_EQ("1009", sol.check("999", "10", "100912"));
    EXPECT_EQ("100", sol.check("1", "99", "100199"));
    EXPECT_EQ("12", sol.check("12", "0", "12122436"));
}
TEST_F(AdditiveNumberTest, CheckF){
    EXPECT_EQ("", sol.check("1", "2", "03"));
    EXPECT_EQ("", sol.check("3", "9", "112"));
    EXPECT_EQ("", sol.check("999", "10", "31009"));
}
TEST_F(AdditiveNumberTest, Small){
    EXPECT_EQ(true, sol.isAdditiveNumber("123"));
    EXPECT_EQ(true, sol.isAdditiveNumber("112358"));
    EXPECT_EQ(true, sol.isAdditiveNumber("199100199"));
    EXPECT_EQ(true, sol.isAdditiveNumber("12012122436"));
}
TEST_F(AdditiveNumberTest, SmallF){
    EXPECT_EQ(false, sol.isAdditiveNumber("10"));
}
