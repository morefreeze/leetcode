#include <gtest/gtest.h>
#include "gray_code.cpp"

class GrayCodeTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(GrayCodeTest, Small){
    int z[] = {0,1,3,2};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.grayCode(2));
}
TEST_F(GrayCodeTest, Small2){
    int z[] = {0,1,3,2,6,7,5,4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.grayCode(3));
}
