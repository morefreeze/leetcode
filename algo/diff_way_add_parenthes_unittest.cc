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
    int z[] = {10,-10,-10,-14,-34};
    EXPECT_EQ(VI(ASZ(z)), sol.diffWaysToCompute("2*3-4*5"));
}
