#include <gtest/gtest.h>
#include "distinct_subsequences.cpp"

class DistinctSubsequencesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(DistinctSubsequencesTest, Small){
    EXPECT_EQ(3, sol.numDistinct("rabbbit", "rabbit"));
    EXPECT_EQ(3, sol.numDistinct("ababc", "abc"));
    EXPECT_EQ(4, sol.numDistinct("aabbc", "abc"));
}
TEST_F(DistinctSubsequencesTest, None){
    EXPECT_EQ(0, sol.numDistinct("aabbc", "abd"));
}
