#include <gtest/gtest.h>
#include "three_sum_closest.cpp"

class ThreeSumClosestTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ThreeSumClosestTest, Small){
    int a[] = {-1, 2, 1, -4};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(2, sol.threeSumClosest(nums, 1));
}
TEST_F(ThreeSumClosestTest, Small2){
    int a[] = {1, 1, 1, 0};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(3, sol.threeSumClosest(nums, 100));
}
TEST_F(ThreeSumClosestTest, Tiny){
    int a[] = {-1, 2, 1};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(2, sol.threeSumClosest(nums, 999999));
}
TEST_F(ThreeSumClosestTest, Big){
    int a[] = {89,-17,-41,9,56,-8,40,38,98,-31,80,-1,-40,-73,28,55,15,89,-83,87,-42,-22,61,64,-94,-33,-38,25,-20,-80,37,99,-72,74,16,-25,-21,-73,-73,-72,65,-4,-72,46,60,7,-25,-14,-58,-50,14,-99,88,50,75,-59,94,-74,25,23,-10,-47,-1,-30,81,-66,54,-64,-1,68,-1,47,55,-59,5,64,45,83,-3,-38,-59,46,33,54,55,9,-13,50,-43,-48,57,97,-55,-13,-25,-9,-20,63,30,88,-4,74,19,-87,-32};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(-285, sol.threeSumClosest(nums, -297));
}
TEST_F(ThreeSumClosestTest, Big2){
    int a[] = {43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(sol.force(nums, -284), sol.threeSumClosest(nums, -284));
}
TEST_F(ThreeSumClosestTest, Big3){
    int a[] = {88,54,99,11,-2,73,2,-4,62,58,80,48,25,49,93,-63,-48,-94,66,-65,-83,95,-5,-2,-62,58,-92,55,-62,-44,-68,-100,-56,61,-96,89,-97,-63,49,-34,25,-84,30,99,9,11,82,93,35,91,78,-8,-29,-41,-35,-20,33,-76,-42,-55,-49,95,43,-100,38,-75,-2,90,-86,-75,-72,47,98,-68,30,-23,20,76,-36,74,98,91,63,97,43,1,-98,52,-38,68,74,-12,41,23,96,17,-10,92,-20,54,-92,77,36,-50,14,-7,41,83,40,24,69,61,15,-51,5,-98,-92,-18,-69,68,-18,-38,62,6,58,-3,72,4,-48,55,-25,83,-26,10,-34,-44,-54,43,34,83,80,51,15,71,76,83,78,84,-98,-31,-38,16,-90,-39,75,-82,-7,37,-20,18,0,63,-98,-14,-73,-59,52,-35,-100,31,-96,-94,78,-25,-5,-61,10,49,-69,-35,40,-17,-34,-100,-93,-7,9,90,-98,17,-58,40,-34,74,85,9,-34,-84,11,-68,80,23,-7,7,-94,40,-35,-51,2,3,-66,-78,-38,-34,-77,85};
    VI nums(a, a+sizeof(a)/sizeof(int));
    EXPECT_EQ(sol.force(nums, -182), sol.threeSumClosest(nums, -182));
}

