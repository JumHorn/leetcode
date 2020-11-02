class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0  # 统计这些数中5的个数'
        while n != 0:
            n = n // 5
            res += n
        return res
