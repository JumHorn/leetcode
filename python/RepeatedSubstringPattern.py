class RepeatedSubstringPattern(object):
    def repeatedSubstringPattern(self,str):
        """
        :type str: str
        :rtype: bool
        """
        #ignore the length of str is 0 
        if len(str)==1:
            return False
        j=1
        while j<len(str)//2+1:
            m=str[0:j]
            print m ,j
            i=j
            while i<len(str):
                if m!=str[i:i+j]:
                    break
                i+=j
            if i==len(str):
                return True
            j+=1
        return False

str="abaababaab"
R=RepeatedSubstringPattern()
print R.repeatedSubstringPattern(str)         