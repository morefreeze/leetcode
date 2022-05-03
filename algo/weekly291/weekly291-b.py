
from typing import List


class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        d = {}
        ans = -1
        for i, c in enumerate(cards):
            if c in d and (ans == -1 or i - d[c] < ans):
                ans = i - d[c] + 1
            d[c] = i
        return ans