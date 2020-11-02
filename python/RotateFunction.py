from typing import List


class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        res, sumval, N, value = 0, sum(A), len(A), 0
        for i in range(N):
            value += i * A[i]
        res = value
        for i in range(1, N):
            value += sumval - N * A[N - i]
            res = max(res, value)
        return res
