#
# @lc app=leetcode id=456 lang=python3
#
# [456] 132 Pattern
#

# @lc code=start
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        left = []
        stack = []
        for i in range(n):
            while len(stack) > 0 and stack[-1][1] >= nums[i]:
                stack.pop()
            left.append(stack[0][0] if len(stack) > 0 and stack[0][0] < i else -1)
            stack.append((i, nums[i]))
        stack = []
        # print(left)
        for i in range(n):
            while len(stack) > 0 and stack[-1][1] <= nums[i]:
                stack.pop()
            # print(i, 'ss', stack)
            if len(stack) > 0:
                li = left[stack[-1][0]]
                if li >= 0 and nums[li] < nums[i]:
                    return True
            stack.append((i, nums[i]))
        return False
# @lc code=end

