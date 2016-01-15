#include <gtest/gtest.h>
#include "edit_distance.cpp"

class EditDistanceTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(EditDistanceTest, Small){
    EXPECT_EQ(1, sol.minDistance("foo", "for"));
}
