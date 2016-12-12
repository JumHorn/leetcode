class WildcardMatching(object):
    def isMatch(self,s,p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        i=0
        j=0
        while i<len(s):
            if j<len(p) and (p[j]==s[i] or p[j]=='?'):
                j+=1
                i+=1
                continue
            elif j<len(p) and p[j]=='*':
                l=p.split("*")
            else:
                return False
        return True


s="aaaa"
p="a?aa"
W=WildcardMatching()
print W.isMatch(s,p)