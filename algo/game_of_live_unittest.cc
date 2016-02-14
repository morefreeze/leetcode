#include <gtest/gtest.h>
#include "game_of_live.cpp"

class GameOfLiveTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(GameOfLiveTest, Small){
    int a0[] = {1,1};
    int a1[] = {1,0};
    VVI b;
    b.PB(VI(ASZ(a0)));
    b.PB(VI(ASZ(a1)));
    int z0[] = {1,1};
    int z1[] = {1,1};
    VVI ans;
    ans.PB(VI(ASZ(z0)));
    ans.PB(VI(ASZ(z1)));
    sol.gameOfLife(b);
    EXPECT_EQ(ans, b);
}
