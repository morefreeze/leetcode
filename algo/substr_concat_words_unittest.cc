#include <gtest/gtest.h>
#include "substr_concat_words.cpp"

class SubstrConcatWordsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SubstrConcatWordsTest, Small){
    string a[] = {"foo", "bar"};
    vector<string> words(a, a+sizeof(a)/sizeof(string));
    int z[] = {0, 9};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, sol.findSubstring("barfoothefoobarman", words));
}
TEST_F(SubstrConcatWordsTest, Small2){
    string a[] = {"0", "1", "2", "3", "4"};
    vector<string> words(a, a+sizeof(a)/sizeof(string));
    int z[] = {0, 4};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, sol.findSubstring("012343210", words));
}
TEST_F(SubstrConcatWordsTest, Small3){
    string a[] = {"0", "1", "2", "3", "4"};
    vector<string> words(a, a+sizeof(a)/sizeof(string));
    int z[] = {0, 1, 2, 3, 4};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, sol.findSubstring("012340123", words));
}
