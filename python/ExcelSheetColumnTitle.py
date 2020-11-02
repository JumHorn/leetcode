class Solution:
    def convertToTitle(self, n: int) -> str:
        res = []
        while n != 0:
            res.append(chr((n - 1) % 26 + ord('A')))
            n = (n - 1) // 26
        res.reverse()
        return "".join(res)
