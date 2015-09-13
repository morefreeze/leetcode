#include <gtest/gtest.h>
#include "product_array_except_self.cpp"

class ProductArrayExceptSelfTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ProductArrayExceptSelfTest, Small){
    int a[] = {1,2,3,4};
    VI nums(ASZ(a));
    int z[] = {24, 12, 8, 6};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.productExceptSelf(nums));
}
