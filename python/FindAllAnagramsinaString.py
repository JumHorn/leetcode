from typing import List


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        shash, phash, res = [0] * 26, [0] * 26, []
        slen, plen = len(s), len(p)
        if slen < plen:
            return res
        for c in p:
            phash[ord(c) - ord('a')] += 1
        for i in range(plen):
            shash[ord(s[i]) - ord('a')] += 1
        if shash == phash:
            res.append(0)
        for i in range(slen - plen):
            shash[ord(s[i]) - ord('a')] -= 1
            shash[ord(s[i+plen]) - ord('a')] += 1
            if shash == phash:
                res.append(i + 1)
        return res
