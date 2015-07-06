#include <gtest/gtest.h>
#include "remove_elem.cpp"

class RemoveElemTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveElemTest, Small){
    int a[] = {1,5,4,2,1,2,1};
    VI vl(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(5, sol.removeElement(vl, 2));
}
TEST_F(RemoveElemTest, Small2){
    int a[] = {1,5,4,2,1,2,1};
    VI vl(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(4, sol.removeElement(vl, 1));
}
TEST_F(RemoveElemTest, Same){
    int a[] = {1,1,1,1,1,1,1};
    VI vl(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(0, sol.removeElement(vl, 1));
}
