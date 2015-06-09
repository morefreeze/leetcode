#include <gtest/gtest.h>
#include "regex_match.cpp"

class RegexMatchTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RegexMatchTest, str2tokens){
    vector<Token> tokens;
    tokens.PB(Token('a', false));
    vector<Token>& my_tokens(sol.str2tokens("a"));
    ASSERT_EQ(SZ(tokens), SZ(my_tokens));
    REP(i, SZ(tokens)){
        EXPECT_TRUE(tokens[i] == my_tokens[i]);
    }

    tokens[0].is_star = true;
    my_tokens = sol.str2tokens("a*");
    ASSERT_EQ(SZ(tokens), SZ(my_tokens));
    REP(i, SZ(tokens)){
        EXPECT_TRUE(tokens[i] == my_tokens[i]);
    }

    tokens.PB(Token('b', true));
    my_tokens = sol.str2tokens("a*b*");
    ASSERT_EQ(SZ(tokens), SZ(my_tokens));
    REP(i, SZ(tokens)){
        EXPECT_TRUE(tokens[i] == my_tokens[i]);
    }

    tokens.PB(Token('.', false));
    tokens.PB(Token('.', false));
    my_tokens = sol.str2tokens("a*b*..");
    ASSERT_EQ(SZ(tokens), SZ(my_tokens));
    REP(i, SZ(tokens)){
        EXPECT_TRUE(tokens[i] == my_tokens[i]);
    }

}

TEST_F(RegexMatchTest, isMatch){
    EXPECT_EQ(false, sol.isMatch("aa", "a"));
    EXPECT_EQ(true, sol.isMatch("aa", "aa"));
    EXPECT_EQ(false, sol.isMatch("aa", "aaa"));
    EXPECT_EQ(true, sol.isMatch("aa", "a*"));
    EXPECT_EQ(true, sol.isMatch("aa", ".*"));
    EXPECT_EQ(true, sol.isMatch("ab", ".*"));
    EXPECT_EQ(true, sol.isMatch("aab", "c*a*b*"));
    EXPECT_EQ(true, sol.isMatch("aaaaaa", "c*a*a*"));
    EXPECT_EQ(true, sol.isMatch("aaaaaa", "c*a*aaaa"));
}

