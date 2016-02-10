#include <gtest/gtest.h>
#include "impl_queue_using_stack.cpp"

class ImplQueueUsingStackTest: public testing::Test{
    protected:
        Queue q;
};
TEST_F(ImplQueueUsingStackTest, Small){
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(1, q.peek());
    q.pop();
    EXPECT_EQ(2, q.peek());
    q.pop();
    EXPECT_EQ(3, q.peek());
    q.pop();
    EXPECT_EQ(4, q.peek());
    q.pop();
    EXPECT_EQ(5, q.peek());
    q.pop();
    EXPECT_TRUE(q.empty());
}
TEST_F(ImplQueueUsingStackTest, Small2){
    q.push(1);
    q.push(2);
    q.push(3);
    EXPECT_EQ(1, q.peek());
    q.pop();
    q.push(4);
    q.push(5);
    // 2345
    EXPECT_EQ(2, q.peek());
    q.pop();
    EXPECT_EQ(3, q.peek());
    q.pop();
    EXPECT_EQ(4, q.peek());
    q.pop();
    EXPECT_EQ(5, q.peek());
    q.pop();
    EXPECT_TRUE(q.empty());
}
