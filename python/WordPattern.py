class WordPattern(object):
    def wordPattern(self,pattern,str):
        """
        :type pattern:str
        :type str:str
        :rtype:bool
        """
        l=str.split(" ")
        if pattern=="" or l=="":
            return False
        if len(pattern)!=len(l):
            return False
        i=0
        dic={}
        while i<len(l):
            if pattern[i] not in dic:
                if l[i] in dic.values():
                    return False
                else:
                    dic[pattern[i]]=l[i]
            else:
                if dic[pattern[i]]!=l[i]:
                    return False
            i=i+1
        return True