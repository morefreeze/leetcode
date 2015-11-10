#include <gtest/gtest.h>
#include "word_break.cpp"

class WordBreakTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(WordBreakTest, Small){
    string a[] = {"leet", "code"};
    unordered_set<string> d(ASZ(a));
    EXPECT_EQ(true, sol.wordBreak("leetcode", d));
    EXPECT_EQ(false, sol.wordBreak("lootcode", d));
}
TEST_F(WordBreakTest, Small2){
    string a[] = {"abc", "abcd", "bcd", "cde", "ab"};
    unordered_set<string> d(ASZ(a));
    EXPECT_EQ(true, sol.wordBreak("abcde", d));
    EXPECT_EQ(true, sol.wordBreak("abbcdcde", d));
    EXPECT_EQ(true, sol.wordBreak("abcdcde", d));
}
TEST_F(WordBreakTest, Repeat){
    string a[] = {"abc", "abcd", "bcd", "cde", "ab"};
    unordered_set<string> d(ASZ(a));
    EXPECT_EQ(true, sol.wordBreak("abcabc", d));
}
TEST_F(WordBreakTest, Repeat2){
    string a[] = {"a","b","bbb","bbbb"};
    unordered_set<string> d(ASZ(a));
    EXPECT_EQ(true, sol.wordBreak("bb", d));
}
TEST_F(WordBreakTest, Big){
    string a[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    unordered_set<string> d(ASZ(a));
    EXPECT_EQ(false, sol.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", d));
}
