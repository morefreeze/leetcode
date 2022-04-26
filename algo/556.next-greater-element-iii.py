#
# @lc app=leetcode id=556 lang=python3
#
# [556] Next Greater Element III
#

# @lc code=start
from itertools import permutations
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        ans = 1<<31
        for i in permutations(str(n)):
            x = int(''.join(i))
            if 1 <= x < (1<<31) and x > n:
                ans = min(ans, x)
        return ans if ans < 1<<31 else -1

# @lc code=end

