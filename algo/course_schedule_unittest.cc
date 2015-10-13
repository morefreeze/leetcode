#include <gtest/gtest.h>
#include "course_schedule.cpp"

class CourseScheduleTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CourseScheduleTest, Small){
    vector<pair<int,int> >p;
    p.PB(MP(0,1));
    EXPECT_EQ(true, sol.canFinish(3, p));
}
