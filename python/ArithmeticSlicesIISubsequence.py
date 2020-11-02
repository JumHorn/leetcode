class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        sum = 0
        dp = [{} for _ in A]  # 生成A长度的list内容是字典
        for i in xrange(len(A)):
            for j in xrange(i):
                diff = A[i]-A[j]
                dp[i][diff] = dp[i].get(diff, 0)+1
                if diff in dp[j]:
                    sum += dp[j][diff]
                    dp[i][diff] += dp[j][diff]
        return sum
