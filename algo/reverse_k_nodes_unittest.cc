#include <gtest/gtest.h>
#include "reverse_k_nodes.cpp"

class ReverseKNodesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ReverseKNodesTest, Small){
    int a[] = {1,2,3,4,5,6,7};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int z[] = {3,2,1,6,5,4,7};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.reverseKGroup(l1, 3)));
}
TEST_F(ReverseKNodesTest, Small2){
    int a[] = {1,2,3,4,5,6};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int z[] = {3,2,1,6,5,4};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.reverseKGroup(l1, 3)));
}
TEST_F(ReverseKNodesTest, k1){
    int a[] = {1,2,3,4,5,6};
    ListNode *l1(vector2List(VI(a, a+sizeof(a)/sizeof(int))));
    int z[] = {1,2,3,4,5,6};
    VI ans(z, z+sizeof(z)/sizeof(int));
    EXPECT_EQ(ans, list2Vector(sol.reverseKGroup(l1, 1)));
}
