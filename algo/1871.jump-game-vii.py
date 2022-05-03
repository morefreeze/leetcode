#
# @lc app=leetcode id=1871 lang=python3
#
# [1871] Jump Game VII
#

# @lc code=start
class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        n = len(s)
        f = [1]
        su = [1]
        for i in range(1, n):
            if s[i] == '1':
                f.append(0)
                su.append(su[-1])
                continue
            left = max(0, i-maxJump)
            right = max(-1, i-minJump)
            f.append(1 if get_sum(su, left, right) > 0 else 0)
            su.append(su[-1] + f[i])
        #print(f, su)
        return f[n-1] == 1

def get_sum(su: List[int], l: int, r: int) -> int:
    if l == 0:
        return su[r] if r >= 0 else 0
    return su[r] - su[l-1]

# @lc code=end

