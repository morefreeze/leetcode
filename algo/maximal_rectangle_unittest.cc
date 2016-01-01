#include <gtest/gtest.h>
#include "maximal_rectangle.cpp"

class MaximalRectangleTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaximalRectangleTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
