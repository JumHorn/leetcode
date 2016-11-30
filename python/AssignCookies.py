class AssignCookies(object):
    def findContentChildren(self,g,s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if len(s)==0:
            return 0
        g.sort()
        s.sort()
        n=0
        i=0
        j=0
        while i<len(g):
            while j<len(s) and s[j]<g[i]:
                j+=1
            if j<len(s):
                n+=1
                i+=1
                j+=1
            else:
                break
        return n