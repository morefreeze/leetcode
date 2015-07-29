#include <gtest/gtest.h>
#include "wildcard_match.cpp"

class WildcardMatchTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(WildcardMatchTest, Leetcode){
    EXPECT_EQ(false, sol.isMatch("aa", "a"));
    EXPECT_EQ(true, sol.isMatch("aa", "aa"));
    EXPECT_EQ(false, sol.isMatch("aaa", "aa"));
    EXPECT_EQ(true, sol.isMatch("aa", "*"));
    EXPECT_EQ(true, sol.isMatch("aa", "a*"));
    EXPECT_EQ(true, sol.isMatch("ab", "?*"));
    EXPECT_EQ(false, sol.isMatch("aab", "c*a*b"));
}
TEST_F(WildcardMatchTest, Small){
    EXPECT_EQ(true, sol.isMatch("", "*"));
    EXPECT_EQ(false, sol.isMatch("aabab", "?**aa?"));
}
TEST_F(WildcardMatchTest, Big){
    EXPECT_EQ(true, sol.isMatch("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaabaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaa", "*b*b*b*"));
}
TEST_F(WildcardMatchTest, TLE){
    EXPECT_EQ(false, sol.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b"));
    EXPECT_EQ(false, sol.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"));
}
