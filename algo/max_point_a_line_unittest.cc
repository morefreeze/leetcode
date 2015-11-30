#include <gtest/gtest.h>
#include "max_point_a_line.cpp"

class MaxPointALineTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MaxPointALineTest, Small){
    vector<Point> p;
    p.PB(Point(1,2));
    p.PB(Point(2,3));
    p.PB(Point(3,4));
    EXPECT_EQ(3, sol.maxPoints(p));
}
TEST_F(MaxPointALineTest, Small2){
    vector<Point> p;
    p.PB(Point(0,0));
    p.PB(Point(1,0));
    EXPECT_EQ(2, sol.maxPoints(p));
}
