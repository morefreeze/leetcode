#include <gtest/gtest.h>
#include "unique_paths2.cpp"

class UniquePaths2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UniquePaths2Test, Small){
    int a0[] = {0,0,0};
    int a1[] = {0,1,0};
    int a2[] = {0,0,0};
    VVI b;
    b.PB(VI(ASZ(a0)));
    b.PB(VI(ASZ(a1)));
    b.PB(VI(ASZ(a2)));
    EXPECT_EQ(2, sol.uniquePathsWithObstacles(b));
}
