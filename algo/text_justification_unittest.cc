#include <gtest/gtest.h>
#include "text_justification.cpp"

class TextJustificationTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(TextJustificationTest, Small){
    string a[] = {"This", "is", "an", "example", "of", "text", "justification."};
    VS words(ASZ(a));
    string z[] = {"This    is    an", "example  of text", "justification.  "};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.fullJustify(words, 16));
}
TEST_F(TextJustificationTest, Empty){
    string a[] = {""};
    VS words(ASZ(a));
    string z[] = {"  "};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.fullJustify(words, 2));
}
TEST_F(TextJustificationTest, LastLine){
    string a[] = {"What","must","be","shall","be."};
    VS words(ASZ(a));
    string z[] = {"What must be","shall be.   "};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.fullJustify(words, 12));
}
