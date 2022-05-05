#
# @lc app=leetcode id=225 lang=python3
#
# [225] Implement Stack using Queues
#

# @lc code=start
class MyStack:
    topEle = None
    q = ([], [])
    cur = 0
    def __init__(self):
        self.topEle = None
        self.q = ([], [])
        self.cur = 0

    def push(self, x: int) -> None:
        self.q[self.cur].append(x)
        self.topEle = None

    def pop(self) -> int:
        while len(self.q[self.cur]) > 1:
            self.q[1-self.cur].append(self.q[self.cur].pop(0))
        ans = self.q[self.cur].pop(0)
        self.cur = 1 - self.cur
        self.topEle = None
        return ans

    def top(self) -> int:
        if self.topEle is not None:
            return self.topEle
        while len(self.q[self.cur]) > 1:
            self.q[1-self.cur].append(self.q[self.cur].pop(0))
        self.topEle = self.q[self.cur].pop(0)
        self.q[1-self.cur].append(self.topEle)
        self.cur = 1 - self.cur
        return self.topEle

    def empty(self) -> bool:
        return len(self.q[self.cur]) == 0
    
    def _switch(self) -> None:
        while len(self.q[self.cur]) > 0:
            self.topEle = self.q[self.cur][0]
            self.q[1-self.cur].append(self.q[self.cur].pop(0))
        self.cur = 1 - self.cur
        return self.topEle


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
# @lc code=end

