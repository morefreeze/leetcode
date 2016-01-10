#include <gtest/gtest.h>
#include "merge_intervals.cpp"

class MergeIntervalsTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MergeIntervalsTest, Sort){
    vector<Interval> ivls;
    ivls.PB(Interval(1,3));
    ivls.PB(Interval(15,18));
    ivls.PB(Interval(2,6));
    ivls.PB(Interval(1,10));
    vector<Interval> ans;
    ans.PB(Interval(1,3));
    ans.PB(Interval(1,10));
    ans.PB(Interval(2,6));
    ans.PB(Interval(15,18));
    sort(ALL(ivls), sol.cmp);
    EXPECT_TRUE(interval_array_eq(ans, ivls));
}
TEST_F(MergeIntervalsTest, SortSmall){
    vector<Interval> ivls;
    ivls.PB(Interval(1,3));
    ivls.PB(Interval(2,6));
    ivls.PB(Interval(8,10));
    ivls.PB(Interval(15,18));
    vector<Interval> ans;
    ans.PB(Interval(1,3));
    ans.PB(Interval(2,6));
    ans.PB(Interval(8,10));
    ans.PB(Interval(15,18));
    sort(ALL(ivls), sol.cmp);
    EXPECT_TRUE(interval_array_eq(ans, ivls));
}
TEST_F(MergeIntervalsTest, Small){
    vector<Interval> ivls;
    ivls.PB(Interval(1,3));
    ivls.PB(Interval(2,6));
    ivls.PB(Interval(8,10));
    ivls.PB(Interval(15,18));
    vector<Interval> ans;
    ans.PB(Interval(1,6));
    ans.PB(Interval(8,10));
    ans.PB(Interval(15,18));
    EXPECT_TRUE(interval_array_eq(ans, sol.merge(ivls)));
}
