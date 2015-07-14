#include <gtest/gtest.h>
#include "next_permutation.cpp"

class NextPermutationTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(NextPermutationTest, Small0){
    int a[] = {1,2,3,4};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {1,2,4,3};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
TEST_F(NextPermutationTest, Small1){
    int a[] = {3,2,4,1};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {3,4,1,2};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
TEST_F(NextPermutationTest, Small2){
    int a[] = {3,2,5,4,1};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {3,4,1,2,5};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
TEST_F(NextPermutationTest, Small3){
    int a[] = {3};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {3};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
TEST_F(NextPermutationTest, Repeat){
    int a[] = {5,1,1};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {1,1,5};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
TEST_F(NextPermutationTest, End){
    int a[] = {5,4,3,2,1};
    VI nums(a, a+sizeof(a)/sizeof(int));
    int z[] = {1,2,3,4,5};
    VI ans(z, z+sizeof(z)/sizeof(int));
    sol.nextPermutation(nums);
    EXPECT_EQ(ans, nums);
}
