from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a = b = c = float("-inf")
        for n in nums:
            if n in (a, b, c):
                continue
            if n > a:
                n, a = a, n
            if n > b:
                n, b = b, n
            if n > c:
                n, c = c, n
        return a if c == float("-inf") else c
