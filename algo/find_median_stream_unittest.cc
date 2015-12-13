#include <gtest/gtest.h>
#include "find_median_stream.cpp"

class FindMedianStreamTest: public testing::Test{
    protected:
};
TEST_F(FindMedianStreamTest, Small){
    MedianFinder mf;
    mf.addNum(1);
    EXPECT_EQ(1, mf.findMedian());
    mf.addNum(2);
    EXPECT_EQ(1.5, mf.findMedian());
    mf.addNum(3);
    EXPECT_EQ(2, mf.findMedian());
}
TEST_F(FindMedianStreamTest, Small2){
    MedianFinder mf;
    REP (i, 5) mf.addNum(1);
    mf.addNum(2);
    EXPECT_EQ(1, mf.findMedian());
}
