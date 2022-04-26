#
# @lc app=leetcode id=407 lang=python3
#
# [407] Trapping Rain Water II
#
# https://leetcode.com/problems/trapping-rain-water-ii/description/
#
# algorithms
# Hard (45.64%)
# Likes:    2684
# Dislikes: 60
# Total Accepted:    68.5K
# Total Submissions: 145.9K
# Testcase Example:  '[[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]'
#
# Given an m x n integer matrix heightMap representing the height of each unit
# cell in a 2D elevation map, return the volume of water it can trap after
# raining.
# 
# 
# Example 1:
# 
# 
# Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
# Output: 4
# Explanation: After the rain, water is trapped between the blocks.
# We have two small ponds 1 and 3 units trapped.
# The total volume of water trapped is 4.
# 
# 
# Example 2:
# 
# 
# Input: heightMap =
# [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
# Output: 10
# 
# 
# 
# Constraints:
# 
# 
# m == heightMap.length
# n == heightMap[i].length
# 1 <= m, n <= 200
# 0 <= heightMap[i][j] <= 2 * 10^4
# 
# 
#

# @lc code=start
import heapq
from typing import List, Mapping
from operator import itemgetter
from collections import defaultdict

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if len(heightMap) == 0:
            return 0
        n, m = len(heightMap), len(heightMap[0])
        h = []
        heapq.heapify(h)
        vi = defaultdict(lambda: defaultdict(bool))
        for i in range(n):
            for j in range(m):
                if i == 0 or i == n-1 or j == 0 or j == m-1:
                    heapq.heappush(h, (heightMap[i][j], i, j))
                    vi[i][j] = True
        minHt = 0
        ans = 0
        direct = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while len(h) > 0:
            hei, x, y = heapq.heappop(h)
            minHt = max(minHt, hei)
            for dx, dy in direct:
                x, y = x + dx, y + dy
                if 0 <= x < n and 0 <= y < m and not vi[x][y]:
                    heapq.heappush(h, (heightMap[x][y], x, y))
                    vi[x][y] = True
                    if heightMap[x][y] < minHt:
                        ans += minHt - heightMap[x][y]
                x, y = x - dx, y - dy
        return ans
# @lc code=end

