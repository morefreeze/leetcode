#include <gtest/gtest.h>
#include "word_search.cpp"

class WordSearchTest: public testing::Test{
    protected:
        Solution sol;
};
vector< vector<char> > make_board(VS s) {
    vector< vector<char> > b;
    REP (i, SZ(s)) {
        vector<char> c;
        REP (j, SZ(s[i])) {
            c.PB(s[i][j]);
        }
        b.PB(c);
    }
    return b;
}
TEST_F(WordSearchTest, Small){
    VS a;
    a.PB("ABCE");
    a.PB("SFCS");
    a.PB("ADEE");
    vector< vector<char> > b(make_board(a));
    EXPECT_EQ(true, sol.exist(b, "ABCCED"));
    EXPECT_EQ(true, sol.exist(b, "SEE"));
    EXPECT_EQ(false, sol.exist(b, "ABCB"));
}
TEST_F(WordSearchTest, LowerCase){
    VS a;
    a.PB("FYCENRD");
    a.PB("KLNFINU");
    a.PB("AAARAHR");
    a.PB("NDKLPNE");
    a.PB("ALANSAP");
    a.PB("OOGOTPN");
    a.PB("HPOLANO");
    vector< vector<char> > b(make_board(a));
    EXPECT_EQ(false, sol.exist(b, "poland"));
}
