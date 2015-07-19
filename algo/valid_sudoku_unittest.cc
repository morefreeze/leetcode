#include <gtest/gtest.h>
#include "valid_sudoku.cpp"

class ValidSudokuTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ValidSudokuTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
