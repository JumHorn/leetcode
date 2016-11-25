class CountandSay(object):
    def countAndSay(self,n):
        '''
        :type n: int
        :rtype:  str
        '''
        if n==1:
            return '1'
        s=self.countAndSay(n-1)
        i=0
        r=''
        while i<len(s):
            j=i+1
            while j<len(s):
                if s[j]==s[i]:
                    j+=1
                else:
                    break
            r=r+'%d%s'%(j-i,s[i])
            i=j
        return r

C=CountandSay()
print C.countAndSay(6)            