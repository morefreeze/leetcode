#include <gtest/gtest.h>
#include "count_primes.cpp"

class CountPrimesTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CountPrimesTest, Small){
    EXPECT_EQ(4, sol.countPrimes(9));
    EXPECT_EQ(0, sol.countPrimes(2));
}
