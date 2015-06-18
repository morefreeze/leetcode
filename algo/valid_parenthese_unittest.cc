#include <gtest/gtest.h>
#include "valid_parenthese.cpp"

class ValidParentheseTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ValidParentheseTest, Small){
    EXPECT_EQ(true, sol.isValid("[]"));
    EXPECT_EQ(true, sol.isValid("()"));
    EXPECT_EQ(true, sol.isValid("{}"));
    EXPECT_EQ(true, sol.isValid("{[()]()}"));
}
TEST_F(ValidParentheseTest, SmallF){
    EXPECT_EQ(false, sol.isValid("[)"));
    EXPECT_EQ(false, sol.isValid(")[]"));
    EXPECT_EQ(false, sol.isValid("[)(]"));
    EXPECT_EQ(false, sol.isValid("([)]"));
}

