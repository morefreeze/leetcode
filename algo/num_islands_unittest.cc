#include <gtest/gtest.h>
#include "num_islands.cpp"

class NumIslandsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NumIslandsTest, Small){
    vector< vector<char> > grid;
    grid.PB(vector<char>(ASZ("11110")));
    grid.PB(vector<char>(ASZ("11010")));
    grid.PB(vector<char>(ASZ("11000")));
    grid.PB(vector<char>(ASZ("00000")));
    EXPECT_EQ(1, sol.numIslands(grid));
}
TEST_F(NumIslandsTest, Small2){
    vector< vector<char> > grid;
    grid.PB(vector<char>(ASZ("11000")));
    grid.PB(vector<char>(ASZ("11000")));
    grid.PB(vector<char>(ASZ("00100")));
    grid.PB(vector<char>(ASZ("00011")));
    EXPECT_EQ(3, sol.numIslands(grid));
}
TEST_F(NumIslandsTest, Zero){
    vector< vector<char> > grid;
    EXPECT_EQ(0, sol.numIslands(grid));
}
