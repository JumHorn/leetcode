class IsomorphicStrings(object):
    def isIsomorphic(self,s,t):
        '''
        :type s:str
        :type t:str
        :rtypr: bool
        '''
        dic={}
        if len(s)!=len(t):
            return False
        i=0
        while i<len(s):
            if dic.has_key(s[i]):
                if dic[s[i]]!=t[i]:
                    return False
            else:
                if t[i] in dic.values():
                    return False
                dic[s[i]]=t[i]
            i+=1
        return True