#include <gtest/gtest.h>
#include "median_two_array.cpp"

TEST(MedianTest, t1){
    int a[] = {};
    int b[] = {4, 5, 6, 7};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(5.5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t2){
    int a[] = {1};
    int b[] = {4, 5, 6, 7};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t3){
    int a[] = {9};
    int b[] = {4, 5, 6, 7};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(6, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t4){
    int a[] = {1, 9};
    int b[] = {4, 5, 6, 7};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(5.5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t5){
    int a[] = {4, 5, 6, 7};
    int b[] = {};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(5.5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t6){
    int a[] = {1};
    int b[] = {1};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(1, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t7){
    int a[] = {1, 3};
    int b[] = {2, 4};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(2.5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t8){
    int a[] = {1, 2};
    int b[] = {1, 2};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(1.5, sol.findMedianSortedArrays(nums1, nums2));
}
TEST(MedianTest, t9){
    int a[] = {1, 2};
    int b[] = {1, 1};
    VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    Solution sol;
    EXPECT_EQ(1, sol.findMedianSortedArrays(nums1, nums2));
}
