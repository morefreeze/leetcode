#include <gtest/gtest.h>
#include "n_queen2.cpp"

class NQueen2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NQueen2Test, Small){
    EXPECT_EQ(92, sol.totalNQueens(8));
}
