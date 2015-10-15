#include <gtest/gtest.h>
#include "simplify_path.cpp"

class SimplifyPathTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SimplifyPathTest, Small){
    EXPECT_EQ("/home", sol.simplifyPath("/home/"));
    EXPECT_EQ("/c", sol.simplifyPath("/a/./b/../../c/"));
}
TEST_F(SimplifyPathTest, Expection){
    EXPECT_EQ("/", sol.simplifyPath("/../.././.."));
}
TEST_F(SimplifyPathTest, Multislash){
    EXPECT_EQ("/home/foo", sol.simplifyPath("/home//foo/"));
}
