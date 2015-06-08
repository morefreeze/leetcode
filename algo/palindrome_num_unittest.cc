#include <gtest/gtest.h>
#include "palindrome_num.cpp"

class PalindromeNumTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PalindromeNumTest, Small){
    EXPECT_EQ(false, sol.isPalindrome(123));
    EXPECT_EQ(true, sol.isPalindrome(1));
    EXPECT_EQ(true, sol.isPalindrome(9));
    EXPECT_EQ(true, sol.isPalindrome(11));
    EXPECT_EQ(true, sol.isPalindrome(191));
    EXPECT_EQ(true, sol.isPalindrome(1111));
}
TEST_F(PalindromeNumTest, LeadZero){
    EXPECT_EQ(false, sol.isPalindrome(1210));
}
TEST_F(PalindromeNumTest, Negative){
    EXPECT_EQ(false, sol.isPalindrome(-2147447412));
}
TEST_F(PalindromeNumTest, Big){
    EXPECT_EQ(true, sol.isPalindrome(1234554321));
    EXPECT_EQ(true, sol.isPalindrome(123454321));
    EXPECT_EQ(false, sol.isPalindrome(1234567890));
}

