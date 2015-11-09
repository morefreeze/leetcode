#include <gtest/gtest.h>
#include "permutation_seq.cpp"

class PermutationSeqTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(PermutationSeqTest, Small){
    EXPECT_EQ("2413", sol.getPermutation(4, 11));
    EXPECT_EQ("123456789", sol.getPermutation(9, 1));
}
