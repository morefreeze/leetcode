#include <gtest/gtest.h>
#include "candy.cpp"

class CandyTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CandyTest, Small){
    int a[] = {1,2,3,4,2,1,2};
    VI r(ASZ(a));
    EXPECT_EQ(15, sol.candy(r));
}
TEST_F(CandyTest, Small2){
    int a[] = {1,2,3,5,4,3,2,1};
    VI r(ASZ(a));
    EXPECT_EQ(21, sol.candy(r));
}
TEST_F(CandyTest, Small3){
    int a[] = {1,2,3,5,4,3,2,1,2};
    VI r(ASZ(a));
    EXPECT_EQ(23, sol.candy(r));
}
TEST_F(CandyTest, Small4){
    int a[] = {1,2,1,2,1,2,1,2,1};
    VI r(ASZ(a));
    EXPECT_EQ(13, sol.candy(r));
}
TEST_F(CandyTest, Small5){
    int a[] = {5,4,3,2,1};
    VI r(ASZ(a));
    EXPECT_EQ(15, sol.candy(r));
}
TEST_F(CandyTest, Small6){
    int a[] = {2,1};
    VI r(ASZ(a));
    EXPECT_EQ(3, sol.candy(r));
}
TEST_F(CandyTest, Equal){
    int a[] = {1,1};
    VI r(ASZ(a));
    EXPECT_EQ(2, sol.candy(r));
}
TEST_F(CandyTest, Equal2){
    int a[] = {1,2,2};
    VI r(ASZ(a));
    EXPECT_EQ(4, sol.candy(r));
}
TEST_F(CandyTest, Equal3){
    int a[] = {1,1,1};
    VI r(ASZ(a));
    EXPECT_EQ(3, sol.candy(r));
}
TEST_F(CandyTest, Equal4){
    int a[] = {1,2,2,1};
    VI r(ASZ(a));
    EXPECT_EQ(6, sol.candy(r));
}
TEST_F(CandyTest, Equal5){
    int a[] = {1,2,3,3,1};
    VI r(ASZ(a));
    EXPECT_EQ(9, sol.candy(r));
}
TEST_F(CandyTest, Equal6){
    // 2 1 1 1 3 2 1 1 1 2
    int a[] = {5,1,1,1,10,2,1,1,1,3};
    VI r(ASZ(a));
    EXPECT_EQ(15, sol.candy(r));
}
