#include <gtest/gtest.h>
#include "skyline.cpp"

class SkylineTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SkylineTest, Small){
    int a0[] = {2,9,10};
    int a1[] = {3,7,15};
    int a2[] = {5,12,12};
    int a3[] = {15,20,10};
    int a4[] = {19,24,8};
    VVI buildings;
    buildings.PB(VI(ASZ(a0)));
    buildings.PB(VI(ASZ(a1)));
    buildings.PB(VI(ASZ(a2)));
    buildings.PB(VI(ASZ(a3)));
    buildings.PB(VI(ASZ(a4)));
    vector<PII> ans;
    ans.PB(MP(2,10));
    ans.PB(MP(3,15));
    ans.PB(MP(7,12));
    ans.PB(MP(12,0));
    ans.PB(MP(15,10));
    ans.PB(MP(20,8));
    ans.PB(MP(24,0));
    EXPECT_EQ(ans, sol.getSkyline(buildings));
}
