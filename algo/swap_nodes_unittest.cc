#include <gtest/gtest.h>
#include "swap_nodes.cpp"

class SwapNodesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(SwapNodesTest, Even){
    int a[] = {1,3,5,7};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int z[] = {3,1,7,5};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.swapPairs(l1)));
}
TEST_F(SwapNodesTest, Odd){
    int a[] = {1,3,5};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int z[] = {3,1,5};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.swapPairs(l1)));
}
