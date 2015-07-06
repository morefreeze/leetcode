#include <gtest/gtest.h>
#include "remove_dup.cpp"

class RemoveDupTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RemoveDupTest, Small){
    int a[] = {1,1,2};
    VI vl(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(2, sol.removeDuplicates(vl));
}
