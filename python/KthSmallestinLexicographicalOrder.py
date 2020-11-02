class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        res = 1
        k -= 1
        while k > 0:
            count = 0
            interval = [res, res + 1]
            while interval[0] <= n:
                count += (min(n + 1, interval[1]) - interval[0])
                interval = [10 * interval[0], 10 * interval[1]]
            if k >= count:
                res += 1
                k -= count
            else:
                res *= 10
                k -= 1
        return res
