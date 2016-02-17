#include <gtest/gtest.h>
#include "unique_binary_tree2.cpp"

class UniqueBinaryTree2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UniqueBinaryTree2Test, Small){
    // this test is simple, but correction test is very complicate
    EXPECT_EQ(5, SZ(sol.generateTrees(3)));
}
