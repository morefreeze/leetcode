#include <gtest/gtest.h>
#include "nim.cpp"

class NimTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NimTest, Small){
    EXPECT_EQ(false, sol.canWinNim(4));
    EXPECT_EQ(true, sol.canWinNim(30));
}
