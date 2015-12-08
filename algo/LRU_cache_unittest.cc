#include <gtest/gtest.h>
#include "LRU_cache.cpp"

class LRUCacheTest: public testing::Test{
    protected:
};
TEST_F(LRUCacheTest, Small){
    LRUCache sol(2);
    sol.set(2,1);
    sol.set(2,2);
    EXPECT_EQ(2, sol.get(2));
    sol.set(1,3);
    sol.set(4,4);
    EXPECT_EQ(-1, sol.get(2));
}
