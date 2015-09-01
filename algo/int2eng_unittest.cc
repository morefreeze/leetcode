#include <gtest/gtest.h>
#include "int2eng.cpp"

class Int2engTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(Int2engTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
