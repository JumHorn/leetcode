#coding=utf-8
class WildcardMatching(object):
    def isMatch(self,s,p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i=0
        j=0
        t=0
        if len(s)==0:
            if self.reallen(p)!=0:
                return False
        if len(s)<self.reallen(p):
            return False
        while i<len(s):
#这里只判断？号
            if j<len(p) and (p[j]==s[i] or p[j]=='?'):
                j+=1
                i+=1
                continue
#这里判断*号
            elif j<len(p) and p[j]=='*':
# #判断最后面的一组
#                 l=p.split('*')
#                 # print l[-1],s[len(s)-len(l[-1]):len(s)],self.isMatch(l[-1],s[len(s)-len(l[-1]):len(s)])
#                 if len(l[-1])!=0:
#                     if not self.isMatch(s[len(s)-len(l[-1]):len(s)],l[-1]):
#                         return False

                while j<len(p):
                    if p[j]=='*':
                        j+=1
                    else:
                        break
                if j==len(p):
                    return True
                else:
                    t=len(s)-self.reallen(p[j:])
                    while i<=t:
                        if p[j]==s[i] or p[j]=='?':
                            if self.isMatch(s[i:],p[j:]):
                                return True
                        i+=1
                    if i==t+1:
                        return False
            else:
                return False
        return True
    def reallen(self,l):
        return len(l)-l.count('*')


s="babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb"
p="b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***b"
# s="abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb"
# p="**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
W=WildcardMatching()
print W.isMatch(s,p)