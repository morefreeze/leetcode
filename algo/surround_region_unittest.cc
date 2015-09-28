#include <gtest/gtest.h>
#include "surround_region.cpp"

class SurroundRegionTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SurroundRegionTest, Small){
    string a[] = {
        "XXXX",
        "XOOX",
        "XXOX",
        "XOXX",
    };
    vector<vector<char> > b;
    for (int i = 0;i < sizeof(a)/sizeof(a[0]);++i){
        b.PB(vector<char>(ALL(a[i])));
    }
    vector<vector<char> > ans;
    string z[] = {
        "XXXX",
        "XXXX",
        "XXXX",
        "XOXX",
    };
    for (int i = 0;i < sizeof(z)/sizeof(z[0]);++i){
        ans.PB(vector<char>(ALL(z[i])));
    }
    sol.solve(b);
    EXPECT_EQ(ans, b);
}
