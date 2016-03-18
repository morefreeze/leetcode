#include <gtest/gtest.h>
#include "remove_dup_letters.cpp"

class RemoveDupLettersTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveDupLettersTest, Small){
    EXPECT_EQ("abc", sol.removeDuplicateLetters("bcabc"));
}
TEST_F(RemoveDupLettersTest, Small2){
    EXPECT_EQ("acdb", sol.removeDuplicateLetters("cbacdcbc"));
}
TEST_F(RemoveDupLettersTest, Small3){
    EXPECT_EQ("bcda", sol.removeDuplicateLetters("cbcdacbc"));
}
TEST_F(RemoveDupLettersTest, Small4){
    EXPECT_EQ("bac", sol.removeDuplicateLetters("bbcaac"));
}
