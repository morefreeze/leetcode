#include <gtest/gtest.h>
#include "dungeon_game.cpp"

class DungeonGameTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(DungeonGameTest, Small){
    VVI map;
    int a[3][3] = { {-2, -3, 3}, {-5, -10, 1}, {10, 30, -5} };
    REP (i, sizeof(a)/sizeof(a[0])){
        map.PB(VI(ASZ(a[i])));
    }
    EXPECT_EQ(7, sol.calculateMinimumHP(map));
}
TEST_F(DungeonGameTest, Small2){
    VVI map;
    int a[3][3] = { {1, -3, 3}, {0, -2, 0}, {-3, -3, -3} };
    REP (i, sizeof(a)/sizeof(a[0])){
        map.PB(VI(ASZ(a[i])));
    }
    EXPECT_EQ(3, sol.calculateMinimumHP(map));
}
TEST_F(DungeonGameTest, Positive){
    VVI map;
    int a[3][3] = { {2, 3, 3}, {5, 10, 1}, {10, 30, 5} };
    REP (i, sizeof(a)/sizeof(a[0])){
        map.PB(VI(ASZ(a[i])));
    }
    EXPECT_EQ(1, sol.calculateMinimumHP(map));
}
