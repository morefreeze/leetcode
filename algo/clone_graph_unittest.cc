#include <gtest/gtest.h>
#include "clone_graph.cpp"

class CloneGraphTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CloneGraphTest, Small){
    int a0[] = {0, 1, 2};
    int a1[] = {1, 2};
    int a2[] = {2, 2};
    VVI nums;
    nums.PB(VI(ASZ(a0)));
    nums.PB(VI(ASZ(a1)));
    nums.PB(VI(ASZ(a2)));
    UndirectedGraphNode *node = vector2Graph(nums);
    printGraph(sol.cloneGraph(node));
}
