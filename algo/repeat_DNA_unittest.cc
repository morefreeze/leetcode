#include <gtest/gtest.h>
#include "repeat_DNA.cpp"

class RepeatDNATest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RepeatDNATest, ConvertDNA2Int){
    EXPECT_EQ(0, sol.convertDNA2Int("AAAAAAAAAA"));
    EXPECT_EQ(1, sol.convertDNA2Int("AAAAAAAAAC"));
    EXPECT_EQ(2, sol.convertDNA2Int("AAAAAAAAAG"));
    EXPECT_EQ(3, sol.convertDNA2Int("AAAAAAAAAT"));
}
TEST_F(RepeatDNATest, Small){
    string z[] = {"AAAAACCCCC", "CCCCCAAAAA",};
    vector<string> ans(ASZ(z));
    EXPECT_EQ(ans, sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
}
TEST_F(RepeatDNATest, One){
    string z[] = {"AAAAAAAAAA",};
    vector<string> ans(ASZ(z));
    EXPECT_EQ(ans, sol.findRepeatedDnaSequences("AAAAAAAAAAA"));
}
TEST_F(RepeatDNATest, Same){
    string z[] = {"AAAAAAAAAA",};
    vector<string> ans(ASZ(z));
    EXPECT_EQ(ans, sol.findRepeatedDnaSequences("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
}
TEST_F(RepeatDNATest, None){
    vector<string> ans;
    EXPECT_EQ(ans, sol.findRepeatedDnaSequences("AAAAACCC"));
}
