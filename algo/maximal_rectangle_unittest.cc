#include <gtest/gtest.h>
#include "maximal_rectangle.cpp"

class MaximalRectangleTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaximalRectangleTest, Small){
    char a0[] = {'0','0','1','0'};
    char a1[] = {'0','1','1','0'};
    char a2[] = {'0','1','1','0'};
    char a3[] = {'1','1','1','0'};
    vector<vector<char> > nums;
    nums.PB(vector<char>(ASZ(a0)));
    nums.PB(vector<char>(ASZ(a1)));
    nums.PB(vector<char>(ASZ(a2)));
    nums.PB(vector<char>(ASZ(a3)));
    EXPECT_EQ(6, sol.maximalRectangle(nums));
}
TEST_F(MaximalRectangleTest, Small2){
    char a0[] = {'0'};
    vector<vector<char> > nums;
    nums.PB(vector<char>(ASZ(a0)));
    EXPECT_EQ(0, sol.maximalRectangle(nums));
}
TEST_F(MaximalRectangleTest, Small3){
    char a0[] = {'1','0'};
    char a1[] = {'1','0'};
    vector<vector<char> > nums;
    nums.PB(vector<char>(ASZ(a0)));
    nums.PB(vector<char>(ASZ(a1)));
    EXPECT_EQ(2, sol.maximalRectangle(nums));
}
