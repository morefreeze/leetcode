#include <gtest/gtest.h>
#include "word_break2.cpp"

class WordBreak2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(WordBreak2Test, Small){
    string a[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> d(ASZ(a));
    string z[] = {"cat sand dog", "cats and dog"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.wordBreak("catsanddog", d));
}
