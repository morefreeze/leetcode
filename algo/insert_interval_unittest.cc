#include <gtest/gtest.h>
#include "insert_interval.cpp"

class InsertIntervalTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(InsertIntervalTest, Small){
    vector<Interval> ints;
    ints.PB(Interval(1,3));
    ints.PB(Interval(6,9));
    vector<Interval> ans;
    ans.PB(Interval(1,5));
    ans.PB(Interval(6,9));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(2,5))));
}
TEST_F(InsertIntervalTest, Small2){
    vector<Interval> ints;
    ints.PB(Interval(1,2));
    ints.PB(Interval(3,5));
    ints.PB(Interval(6,7));
    ints.PB(Interval(8,10));
    ints.PB(Interval(12,16));
    vector<Interval> ans;
    ans.PB(Interval(1,2));
    ans.PB(Interval(3,10));
    ans.PB(Interval(12,16));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(4,9))));
}
TEST_F(InsertIntervalTest, Small3){
    vector<Interval> ints;
    ints.PB(Interval(1,5));
    vector<Interval> ans;
    ans.PB(Interval(0,5));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(0,5))));
}
TEST_F(InsertIntervalTest, Small4){
    vector<Interval> ints;
    ints.PB(Interval(0,5));
    ints.PB(Interval(9,12));
    vector<Interval> ans;
    ans.PB(Interval(0,5));
    ans.PB(Interval(7,16));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(7,16))));
}
TEST_F(InsertIntervalTest, Inside){
    vector<Interval> ints;
    ints.PB(Interval(1,5));
    vector<Interval> ans;
    ans.PB(Interval(1,5));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(2,3))));
}
TEST_F(InsertIntervalTest, CoverStart){
    vector<Interval> ints;
    ints.PB(Interval(1,3));
    ints.PB(Interval(6,9));
    vector<Interval> ans;
    ans.PB(Interval(0,5));
    ans.PB(Interval(6,9));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(0,5))));
}
TEST_F(InsertIntervalTest, BeforeStart){
    vector<Interval> ints;
    ints.PB(Interval(2,3));
    ints.PB(Interval(6,9));
    vector<Interval> ans;
    ans.PB(Interval(0,1));
    ans.PB(Interval(2,3));
    ans.PB(Interval(6,9));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(0,1))));
}
TEST_F(InsertIntervalTest, AfterEnd){
    vector<Interval> ints;
    ints.PB(Interval(2,3));
    ints.PB(Interval(6,9));
    vector<Interval> ans;
    ans.PB(Interval(2,3));
    ans.PB(Interval(6,9));
    ans.PB(Interval(10,12));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(10,12))));
}
TEST_F(InsertIntervalTest, InsertNew){
    vector<Interval> ints;
    ints.PB(Interval(3,5));
    ints.PB(Interval(12,15));
    vector<Interval> ans;
    ans.PB(Interval(3,5));
    ans.PB(Interval(6,6));
    ans.PB(Interval(12,15));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(6,6))));
}
TEST_F(InsertIntervalTest, Empty){
    vector<Interval> ints;
    vector<Interval> ans;
    ans.PB(Interval(2,3));
    EXPECT_TRUE(interval_array_eq(ans, sol.insert(ints, Interval(2,3))));
}
