#include <gtest/gtest.h>
#include "create_maximum_number.cpp"

class CreateMaximumNumberTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(CreateMaximumNumberTest, Small){
    int a1[] = {3,4,6,5};
    VI nums1(ASZ(a1));
    int a2[] = {9,1,2,5,8,3};
    VI nums2(ASZ(a2));
    int z[] = {9,8,6,5,3};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxNumber(nums1, nums2, 5));
}
TEST_F(CreateMaximumNumberTest, Small2){
    int a1[] = {6,7};
    VI nums1(ASZ(a1));
    int a2[] = {6,0,4};
    VI nums2(ASZ(a2));
    int z[] = {6,7,6,0,4};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxNumber(nums1, nums2, 5));
}
TEST_F(CreateMaximumNumberTest, Small3){
    int a1[] = {3,9};
    VI nums1(ASZ(a1));
    int a2[] = {8,9};
    VI nums2(ASZ(a2));
    int z[] = {9,8,9};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxNumber(nums1, nums2, 3));
}
TEST_F(CreateMaximumNumberTest, My){
    int a1[] = {9,1};
    VI nums1(ASZ(a1));
    int a2[] = {8,2};
    VI nums2(ASZ(a2));
    int z[] = {9,8};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxNumber(nums1, nums2, 2));
}
TEST_F(CreateMaximumNumberTest, Big){
    int a1[] = {7,3,1,0,4,0,1,5,4,1,8,7,9,1,1,2,3,1,0,3,6,9,3,7};
    VI nums1(ASZ(a1));
    int a2[] = {4,1,3,7,4,4,2,6,0,0,2,4,9,3,2,1,2,3,8,1,7,4,6,7,4,6,2,3,6,9,3,0,9,4,1,4,6,4,6,3,8,0,2,5,1,5,0,8,1,4,1,5,0,7,8,7,1,5,0,8,2,8,5,5,7,2,7,4,2,7,8,5,8,5,1,9,8,1,4,0,3,2,2,0,0,8,7,4,1,1,0,2,7,7,1,6,1,7,8,3,0,9,4,9,8,1,3,3,2,6,1,8,5,5,7,7,9,1,5,1};
    VI nums2(ASZ(a2));
    int z[] = {9,9,7,7,4,4,2,6,0,0,2,4,9,3,2,1,2,3,8,1,7,4,6,7,4,6,2,3,6,9,3,0,9,4,1,4,6,4,6,3,8,0,2,5,1,5,0,8,1,4,1,5,0,7,8,7,1,5,0,8,2,8,5,5,7,2,7,4,2,7,8,5,8,5,1,9,8,1,4,0,3,2,2,0,0,8,7,4,1,1,0,2,7,7,1,6,1,7,8,3,0,9,4,9,8,1,3,3,2,6,1,8,5,5,7,7,9,1,5,1};
    VI ans(ASZ(z));
    EXPECT_EQ(ans, sol.maxNumber(nums1, nums2, 120));
}

