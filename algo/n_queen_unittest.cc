#include <gtest/gtest.h>
#include "n_queen.cpp"

class NQueenTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NQueenTest, Small){
    string z0[] = {
        ".Q..",
        "...Q",
        "Q...",
        "..Q.",
    };
    string z1[] = {
        "..Q.",
        "Q...",
        "...Q",
        ".Q..",
    };
    vector< vector<string> > ans;
    ans.PB(vector<string>(z0, z0+ASZ(z0)));
    ans.PB(vector<string>(z1, z1+ASZ(z1)));
    EXPECT_EQ(ans, sol.solveNQueens(4));
}
TEST_F(NQueenTest, Normal){
    vector< vector<string> > ans(sol.solveNQueens(8));
    EXPECT_EQ(92, SZ(ans));
}
TEST_F(NQueenTest, Big){
    vector< vector<string> > ans(sol.solveNQueens(12));
    EXPECT_EQ(14200, SZ(ans));
}

