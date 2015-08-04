#include <gtest/gtest.h>
#include "rotate_image.cpp"

class RotateImageTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(RotateImageTest, Odd){
    int a0[] = {1,2,3};
    int a1[] = {4,5,6};
    int a2[] = {7,8,9};
    VVI m;
    m.PB(VI(a0, a0+ASZ(a0)));
    m.PB(VI(a1, a1+ASZ(a1)));
    m.PB(VI(a2, a2+ASZ(a2)));
    sol.rotate(m);
    int z0[] = {7,4,1};
    int z1[] = {8,5,2};
    int z2[] = {9,6,3};
    VVI ans;
    ans.PB(VI(z0, z0+ASZ(z0)));
    ans.PB(VI(z1, z1+ASZ(z1)));
    ans.PB(VI(z2, z2+ASZ(z2)));
    EXPECT_EQ(ans, m);
}
TEST_F(RotateImageTest, Even){
    int a0[] = {1,2,3,4};
    int a1[] = {5,6,7,8};
    int a2[] = {9,10,11,12};
    int a3[] = {13,14,15,16};
    VVI m;
    m.PB(VI(a0, a0+ASZ(a0)));
    m.PB(VI(a1, a1+ASZ(a1)));
    m.PB(VI(a2, a2+ASZ(a2)));
    m.PB(VI(a3, a3+ASZ(a3)));
    sol.rotate(m);
    int z0[] = {13,9,5,1};
    int z1[] = {14,10,6,2};
    int z2[] = {15,11,7,3};
    int z3[] = {16,12,8,4};
    VVI ans;
    ans.PB(VI(z0, z0+ASZ(z0)));
    ans.PB(VI(z1, z1+ASZ(z1)));
    ans.PB(VI(z2, z2+ASZ(z2)));
    ans.PB(VI(z3, z3+ASZ(z3)));
    EXPECT_EQ(ans, m);
}
