from collections import Counter
class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        pp = [x % p == 0 for x in nums]
        ans = []
        n = len(nums)
        for i in range(n):
            p_num = 0
            for j in range(i, n):
                p_num += int(pp[j])
                if p_num > k:
                    break
                ans.append(tuple(nums[i:j+1]))
        return len(Counter(ans))