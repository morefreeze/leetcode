#include <gtest/gtest.h>
#include "diff_way_add_parenthes.cpp"

class DiffWayAddParenthesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(DiffWayAddParenthesTest, Small){
    int z[] = {0, 2};
    EXPECT_EQ(VI(ASZ(z)), sol.diffWaysToCompute("2-1-1"));
}
TEST_F(DiffWayAddParenthesTest, One){
    int z[] = {42};
    EXPECT_EQ(VI(ASZ(z)), sol.diffWaysToCompute("42"));
}
TEST_F(DiffWayAddParenthesTest, Adv){
    int z[] = {10, -14, -10, -10, -34};
    EXPECT_EQ(VI(ASZ(z)), sol.diffWaysToCompute("2*3-4*5"));
}
TEST_F(DiffWayAddParenthesTest, Big){
    int z[] = {37510, -1694, -13310, -13310, -52514};
    EXPECT_EQ(VI(ASZ(z)), sol.diffWaysToCompute("22*33-44*55"));
}
