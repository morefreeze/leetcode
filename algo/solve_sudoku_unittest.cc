#include <gtest/gtest.h>
#include "solve_sudoku.cpp"

class SolveSudokuTest: public testing::Test{
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
TEST_F(SolveSudokuTest, TileCmp){
    // 1 0010 1011
    Tile lhs(0x12b, 0, 2);
    // 1 0101 1101
    Tile rhs(0x15d, 6, 2);
    EXPECT_LT(rhs, lhs);
}
TEST_F(SolveSudokuTest, TileCmpEq){
    Tile lhs(0x12b, 0, 2);
    Tile rhs(0x1f, 6, 2);
    EXPECT_LT(rhs, lhs);
}
TEST_F(SolveSudokuTest, Bin2Int){
    EXPECT_EQ(6, sol.bin2Int(0x40));
    EXPECT_EQ(8, sol.bin2Int(0x140));
    EXPECT_EQ(0, sol.bin2Int(0x1));
}
TEST_F(SolveSudokuTest, MakeCandidates){
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
    sol.make_candidates(board);
    Tile cur(sol.pq[0].top());
    Tile ans(0x40, 6, 5);
    EXPECT_EQ(ans.mask, cur.mask);
    EXPECT_EQ(ans.x, cur.x);
    EXPECT_EQ(ans.y, cur.y);
}
void pr_board(vector < vector <char> >& board){
    REP (i, SZ(board)){
        REP (j, SZ(board[i])){
            cout << board[i][j];
        }
        cout << endl;
    }
}
TEST_F(SolveSudokuTest, Small){
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
    sol.solveSudoku(board);
    pr_board(board);
}
TEST_F(SolveSudokuTest, Crazy){
    string bb[] = {".........",
                   ".........",
                   ".........",
                   ".........",
                   ".........",
                   ".........",
                   ".........",
                   ".........",
                   ".........",
    };
    vector <vector <char> > board;
    make_board(bb, board);
    sol.solveSudoku(board);
    pr_board(board);
}
