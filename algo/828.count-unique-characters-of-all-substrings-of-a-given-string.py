#
# @lc app=leetcode id=828 lang=python3
#
# [828] Count Unique Characters of All Substrings of a Given String
#

# @lc code=start
class Solution:
    def uniqueLetterString(self, s: str) -> int:
        d = {chr(i+ord('A')): [-1, -1] for i in range(26)}
        cnt, ans = 0, 0
        for i, c in enumerate(s):
            d[c].append(i)
            cnt += (d[c][2] - d[c][1]) - (d[c][1] - d[c][0])
            ans += cnt
            d[c].pop(0)
        return ans
# @lc code=end

