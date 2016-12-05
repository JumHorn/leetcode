class ValidNumber(object):
    def isNumber(self,s):
        """
        :type s: str
        :rtype: bool
        """
        s=s.strip()
        if len(s)==0:
            return False
        d=['0','1','2','3','4','5','6','7','8','9','.']
        c=['+','-','e']
        for n in s:
            if n not in d and n not in c:
                return False
        if s[0] == 'e' or s[len(s)-1] in c:
            return False
        digits=s.split('e')
        if len(digits)>2:
            return False
        i=0
        for n in digits:
            if len(n)==0:
                return False
            if '.' in n and i==1:
                return False
            if '.' in n:
                l=n.split('.')
                # if len(l)!=2:
                #     return False
                # else:
                # print l,len(l)
                if len(l)==2:
                # print n
                    if not self.check1(n):
                        return False
                else:
                    return False
            else:
                if not self.check0(n):
                    return False
            i+=1
            # l=n.split('.')
            # if len(l)>2:
            #     return False
            # if len(l)
        return True

    def check0(self,l):
        if not self.check_sign(l):
            return False
        return True
    def check1(self,l):
        # if len(l)==0:
        #     return False
        if not self.check_sign(l):
            return False
        if len(l)==1:
            return False
        return True
    def check_sign(self,l):
        if '-' in l:
            if len(l)==1:
                return False
            if l[0]!='-':
                return False
            else:
                if '.' in l and len(l)==2:
                    return False
            if len(l)>=3 and '-' in l[1:len(l)-1]:
                return False 
        if '+' in l:
            if len(l)==1:
                return False
            if l[0]!='+':
                return False
            else:
                if '.' in l and len(l)==2:
                    return False
            if len(l)>=3 and '+' in l[1:len(l)-1]:
                return False   
        return True     

s="+."
V=ValidNumber()
print V.isNumber(s)               