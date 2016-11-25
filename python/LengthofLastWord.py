class LengthofLastWord(object):
    def lengthOfLastWord(self,s):
        '''
        :type s:str
        :rtype:int
        '''
        if s=="":
            return 0
        n=0
        i=len(s)-1
        while i>=0 and s[i]=='':
            i=i-1
        print i
        while i>=0 and s[i]!='':
            i=i-1
            n=n+1
        return n

L=LengthofLastWord()
print L.lengthOfLastWord("qwer  ")
            