from typing import List


class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        sum = 0
        dp = [{} for _ in A]  # 生成A长度的list内容是字典
        for i in range(len(A)):
            for j in range(i):
                diff = A[i]-A[j]
                dp[i][diff] = dp[i].get(diff, 0)+1
                if diff in dp[j]:
                    sum += dp[j][diff]
                    dp[i][diff] += dp[j][diff]
        return sum
