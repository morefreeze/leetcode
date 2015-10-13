#include <gtest/gtest.h>
#include "course_schedule2.cpp"

class CourseSchedule2Test: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CourseSchedule2Test, Small){
    vector<pair<int,int> > p;
    p.PB(MP(1,0));
    p.PB(MP(2,0));
    p.PB(MP(3,1));
    p.PB(MP(3,2));
    int z[] = {0,1,2,3};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.findOrder(4, p));
}
