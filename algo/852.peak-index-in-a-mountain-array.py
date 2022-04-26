#
# @lc app=leetcode id=852 lang=python3
#
# [852] Peak Index in a Mountain Array
#

# @lc code=start
from typing import List


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr)-1
        while l < r:
            mid = (l+r+1) // 2
            if arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]:
                return mid
            elif arr[mid-1] < arr[mid] < arr[mid+1]:
                l = mid + 1
            else:
                r = mid - 1
        return (l+r+1) // 2
# @lc code=end

