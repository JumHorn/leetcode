class WildcardMatch(object):
    def isMatch(self,s,p):
        i=0
        j=0
        m=0
        n=0
        if len(s)<len(p)-p.count('*'):
            return False
        while i!=len(s):
            if j<len(p) and (p[j]=='?' or p[j]==s[i]):
                i+=1
                j+=1
                continue
            if j<len(p) and p[j]=='*':
                n=j
                j+=1
                m=i
                continue
            if n<len(p) and p[n]=='*':
                j=n+1
                i=m+1
                m+=1
                continue
            return False
        while j<len(p) and p[j]=='*':
            j+=1
        return j==len(p)

s="aa"
p="*"
# s="abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
# p="**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
W=WildcardMatch()
print W.isMatch(s,p)