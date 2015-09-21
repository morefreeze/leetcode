#include <gtest/gtest.h>
#include "unique_binary_tree.cpp"

class UniqueBinaryTreeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UniqueBinaryTreeTest, Small){
    EXPECT_EQ(1, sol.numTrees(0));
    EXPECT_EQ(1, sol.numTrees(1));
    EXPECT_EQ(5, sol.numTrees(3));
    EXPECT_EQ(14, sol.numTrees(4));
}
TEST_F(UniqueBinaryTreeTest, Big){
    EXPECT_EQ(9694845, sol.numTrees(15));
}
