#include <gtest/gtest.h>
#include "max_depth_BST.cpp"

class MaxDepthBSTTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaxDepthBSTTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
