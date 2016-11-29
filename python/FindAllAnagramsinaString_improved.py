class FindAllAnagramsinaString(object):
    def findAllAnagramsinaString(self,s,p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        result=[]
        if len(s)<len(p):
            return result
        data={}
        for n in p:
            if n not in data:
                data[n]=1
            else:
                data[n]+=1
        l=0
        r=0
        count=len(p)
        while r<len(s):
            if s[r] in data:
                data[s[r]]-=1
                count-=1
            r+=1
            print s[l:r],count
            print data
            if count==0:
                t=0
                for n in data.values():
                    if n!=0:
                        t=1
                        break
                if t==0:
                    result.append(l)
            if r-l==len(p):
                if s[l] in data:
                    data[s[l]]+=1
                    count+=1
                l+=1
        return result

s="cbaebabacd"
p="abc"
F=FindAllAnagramsinaString()
print F.findAllAnagramsinaString(s,p)