#include <gtest/gtest.h>
#include "valid_sudoku.cpp"

class ValidSudokuTest: public testing::Test{
    protected:
        Solution sol;
};
void make_board(string bb[], vector< vector <char> > &board){
    REP (i, 9){
        vector <char> tmp;
        REP (j, 9){
            tmp.PB(bb[i][j]);
        }
        board.PB(tmp);
    }
}
TEST_F(ValidSudokuTest, Small){
    string bb[] = {"53..7....",
                   "6..195...",
                   ".98....6.",
                   "8...6...3",
                   "4..8.3..1",
                   "7...2...6",
                   ".6....28.",
                   "...419..5",
                   "....8..79",
    };
    vector <vector <char> > board;
    make_board(bb, board);
    EXPECT_EQ(true, sol.isValidSudoku(board));
}
TEST_F(ValidSudokuTest, Small2){
    string bb[] = {"..4...63.",
                   ".........",
                   "5......9.",
                   "...56....",
                   "4.3.....1",
                   "...7.....",
                   "...5.....",
                   ".........",
                   "........."
    };
    vector <vector <char> > board;
    make_board(bb, board);
    EXPECT_EQ(false, sol.isValidSudoku(board));
}
