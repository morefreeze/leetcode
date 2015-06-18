#include <gtest/gtest.h>
#include "letter_comb_phone.cpp"

class LetterCombPhoneTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(LetterCombPhoneTest, Small){
    vector<string> ans;
    ans.PB("ad");
    ans.PB("ae");
    ans.PB("af");
    ans.PB("bd");
    ans.PB("be");
    ans.PB("bf");
    ans.PB("cd");
    ans.PB("ce");
    ans.PB("cf");
    EXPECT_EQ(ans, sol.letterCombinations("23"));
}
