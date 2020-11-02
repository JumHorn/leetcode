class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        data = self.countAndSay(n - 1)
        res = ""
        pre, count = '\0', 0
        for c in data:
            if pre != c:
                if count != 0:
                    res += str(count) + pre
                pre = c
                count = 1
            else:
                count += 1
        res += str(count)+pre
        return res
