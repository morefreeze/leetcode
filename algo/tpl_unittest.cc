#include <gtest/gtest.h>
#include "app.cpp"

class AppTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(AppTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
