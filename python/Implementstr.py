class Implementstr(object):
    def strStr(self,haystack,needle):
        if not needle:
            return 0
        for i,n in enumerate(haystack):
            if n==needle[0]:
                if len(haystack)-i >= len(needle):
                    for j,m in enumerate(needle):
                        if m != haystack[j+i]:
                            break
                        else:
                            if j==len(needle)-1:
                                return i
        return -1
                
