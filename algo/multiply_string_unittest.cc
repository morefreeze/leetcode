#include <gtest/gtest.h>
#include "multiply_string.cpp"

class MultiplyStringTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(MultiplyStringTest, Small){
    EXPECT_EQ("39483", sol.multiply("123", "321"));
    EXPECT_EQ("998001", sol.multiply("999", "999"));
}
TEST_F(MultiplyStringTest, Big){
    EXPECT_EQ("6378643926150574897583591029983", sol.multiply("789315890678901", "8081230850001283"));
    EXPECT_EQ("999999999998000000000001", sol.multiply("999999999999", "999999999999"));
}
TEST_F(MultiplyStringTest, Zero){
    EXPECT_EQ("0", sol.multiply("789315890678901", "0"));
    EXPECT_EQ("0", sol.multiply("0", "999999999999"));
}
