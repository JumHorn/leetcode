class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        d, seen = {}, set()
        for i in range(len(s)):
            if s[i] not in d and t[i] not in seen:
                d[s[i]] = t[i]
                seen.add(t[i])
            if d.get(s[i]) != t[i]:
                return False
        return True
