class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        p = pattern
        t = s.split()
        return len(set(zip(p, t))) == len(set(p)) == len(set(t)) and len(p) == len(t)
