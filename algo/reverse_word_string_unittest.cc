#include <gtest/gtest.h>
#include "reverse_word_string.cpp"

class ReverseWordStringTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ReverseWordStringTest, Trim){
    string s = "  a  te ew qe r  er  eee rq  ";
    sol.trim(s);
    EXPECT_EQ("a te ew qe r er eee rq", s);
}
TEST_F(ReverseWordStringTest, Small){
    string s = "  sky is blue";
    sol.reverseWords(s);
    EXPECT_EQ("blue is sky", s);
}
TEST_F(ReverseWordStringTest, Small2){
    string s = "  the sky is blue";
    sol.reverseWords(s);
    EXPECT_EQ("blue is sky the", s);
}
