#include <gtest/gtest.h>
#include "scramble_string.cpp"

class ScrambleStringTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ScrambleStringTest, Small){
    EXPECT_EQ(true, sol.isScramble("great", "rgtae"));
    EXPECT_EQ(true, sol.isScramble("great", "rgtea"));
    EXPECT_EQ(false, sol.isScramble("aa", "ab"));
}
TEST_F(ScrambleStringTest, Big){
    EXPECT_EQ(false, sol.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb"));
}
