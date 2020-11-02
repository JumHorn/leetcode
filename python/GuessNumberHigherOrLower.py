# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
def guess(num: int) -> int:


class Solution:
    def guessNumber(self, n: int) -> int:
        lo, hi = 1, n
        while lo < hi:
            mi = (hi - lo) // 2 + lo
            g = guess(mi)
            if g == 0:
                return mi
            if g > 0:
                lo = mi + 1
            else:
                hi = mi - 1
        return lo
