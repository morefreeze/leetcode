#include <gtest/gtest.h>
#include "restore_ip.cpp"

class RestoreIpTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RestoreIpTest, Small){
    string z[] = {"255.255.11.135", "255.255.111.35"};
    vector<string> ans(ASZ(z));
    EXPECT_EQ(ans, sol.restoreIpAddresses("25525511135"));
}
TEST_F(RestoreIpTest, Zero){
    string z[] = {"0.0.0.0"};
    vector<string> ans(ASZ(z));
    EXPECT_EQ(ans, sol.restoreIpAddresses("0000"));
}
