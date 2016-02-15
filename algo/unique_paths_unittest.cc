#include <gtest/gtest.h>
#include "unique_paths.cpp"

class UniquePathsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(UniquePathsTest, Small){
    EXPECT_EQ(28, sol.uniquePaths(3,7));
}
