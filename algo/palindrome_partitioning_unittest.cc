#include <gtest/gtest.h>
#include "palindrome_partitioning.cpp"

class PalindromePartitioningTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PalindromePartitioningTest, Small){
    string z0[] = {"a", "a", "b"};
    string z1[] = {"aa", "b"};
    vector<VS> ans;
    ans.PB(VS(ASZ(z0)));
    ans.PB(VS(ASZ(z1)));
    EXPECT_EQ(ans, sol.partition("aab"));
}
