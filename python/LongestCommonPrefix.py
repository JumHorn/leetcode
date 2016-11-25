#coding=UTF-8
class LongestCommonPrefix(object):
    def longestCommonPrefix(self,strs):
        '''
        :type strs:List[str]
        :rtype: str
        '''
        if not strs:
            return ''
        min=2147483648
        for n in strs:
            if len(n)<min:
                min=len(n)
        if min==0:
            return ''
#        print min
        l=[]
        i=0
        while i<min:
            j=0
            while j<len(strs)-1:
                if strs[j][i]!=strs[j+1][i]:
                    return ''.join(l)
                j=j+1
            l.insert(len(l),strs[j][i])
            i=i+1
        return ''.join(l)

strs=['aa','ab']
longest=LongestCommonPrefix()
print longest.longestCommonPrefix(strs)
                
