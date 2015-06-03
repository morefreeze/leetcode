#include <gtest/gtest.h>
#include "longest_palindromic_substring.cpp"

TEST(Palindromic, Odd){
    Solution sol;
    EXPECT_EQ("abcba", sol.longestPalindrome("ababcba"));
    EXPECT_EQ("a", sol.longestPalindrome("a"));
    EXPECT_EQ("ccccccc", sol.longestPalindrome("ccccccc"));
}

TEST(Palindromic, Even){
    Solution sol;
    EXPECT_EQ("abba", sol.longestPalindrome("ababba"));
    EXPECT_EQ("aaaaaaaa", sol.longestPalindrome("aaaaaaaa"));

}
