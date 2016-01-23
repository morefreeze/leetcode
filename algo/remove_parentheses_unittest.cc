#include <gtest/gtest.h>
#include "remove_parentheses.cpp"

class RemoveParenthesesTest: public testing::Test{
    protected:
        Solution sol;
};
bool checkAns(VS &lhs, VS &rhs) {
    if (SZ(lhs) != SZ(rhs)) {
        cerr << "Size is dismatched " << SZ(lhs) << " " << SZ(rhs) << endl;
        return false;
    }
    unordered_set<string> t;
    for (auto s : lhs) {
        t.insert(s);
    }
    for (auto s : rhs) {
        auto pos = t.find(s);
        if (pos == t.end()) {
            cerr << "rhs is missing " << s << endl;
            return false;
        }
        t.erase(pos);
    }
    if (!t.empty()) {
        cerr << "lhs is missing " << *t.begin() << endl;
        return false;
    }
    return true;
}
TEST_F(RemoveParenthesesTest, Small){
    string z[] = {"()()()", "(())()"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses("()())()");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Small2){
    string z[] = {"(a)()()", "(a())()"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses("(a)())()");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Small3){
    string z[] = {""};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses(")(");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Letter){
    string z[] = {"ov"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses(")o(v(");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Letter2){
    string z[] = {"r()()","r(())","(r)()","(r())"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses("(r(()()(");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Big){
    string z[] = {"(())()()(())()","()()()()(())()"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses("()()))()()(())()(((");
    EXPECT_TRUE(checkAns(ans, ans2));
}
TEST_F(RemoveParenthesesTest, Big2){
    string z[] = {"(((())))(()(()()))(())","()((()))(()(()()))(())"};
    VS ans(ASZ(z));
    VS ans2 = sol.removeInvalidParentheses(")()((()))))(()(()()))((())(");
    EXPECT_TRUE(checkAns(ans, ans2));
}
