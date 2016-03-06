#include <gtest/gtest.h>
#include "remove_dup_letters.cpp"

class RemoveDupLettersTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveDupLettersTest, Small){
    EXPECT_EQ(123, sol.func("123"));
}
