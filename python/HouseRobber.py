from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        f1, f2 = 0, 0
        for n in nums:
            f3 = max(f1 + n, f2)
            f1 = f2
            f2 = f3
        return f2
