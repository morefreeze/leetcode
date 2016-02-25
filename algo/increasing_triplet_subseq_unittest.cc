#include <gtest/gtest.h>
#include "increasing_triplet_subseq.cpp"

class IncreasingTripletSubseqTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(IncreasingTripletSubseqTest, Small){
    int a[] = {1,2,3,4,5};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Small2){
    int a[] = {5,4,3,2,1};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Small3){
    int a[] = {3,4,1,2,3};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Small4){
    int a[] = {3,4,1,5};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Small5){ int a[] = {2,1,5,0,3};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Small6){
    int a[] = {5,1,5,5,2,5,4};
    VI nums(ASZ(a));
    EXPECT_EQ(true, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Negative){
    int a[] = {2,4,-2,-3};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Less){
    int a[] = {3,4};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.increasingTriplet(nums));
}
TEST_F(IncreasingTripletSubseqTest, Empty){
    int a[] = {};
    VI nums(ASZ(a));
    EXPECT_EQ(false, sol.increasingTriplet(nums));
}
