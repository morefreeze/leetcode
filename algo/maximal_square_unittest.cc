#include <gtest/gtest.h>
#include "maximal_square.cpp"

class MaximalSquareTest: public testing::Test{
    protected:
        Solution sol;
};
vector<char> string2char(const string &s) {
    vector<char> a;
    REP (i, SZ(s)) {
        a.PB(s[i]);
    }
    return a;
}
TEST_F(MaximalSquareTest, Small){
    string a[] = {
        "10100",
        "10111",
        "11111",
        "10010",
    };
    vector< vector<char> > map;
    REP (i, 4) {
        map.PB(string2char(a[i]));
    }
    EXPECT_EQ(4, sol.maximalSquare(map));
}
TEST_F(MaximalSquareTest, Small2){
    string a[] = {
        "0110010101",
        "0010101010",
        "1000010110",
        "0111111010",
        "0011111110",
        "1101011110",
        "0001100010",
        "1101100111",
        "0101101011"
    };
    vector< vector<char> > map;
    REP (i, 9) {
        map.PB(string2char(a[i]));
    }
    EXPECT_EQ(4, sol.maximalSquare(map));
}

