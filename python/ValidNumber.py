class ValidNumber(object):
    def isNumber(self,s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s)==0:
            return False
        d=['0','1','2','3','4','5','6','7','8','9']
        c=['.','e']
        for n in s:
            if n not in d and n not in c:
                return False
        if s[0] in c or s[len(s)-1] in c:
            return False
        digits=s.split('e')
        for n in digits:
            if '.' in n:
                l=n.split('.')
                if len(l)!=2:
                    return False
                else:
                    if not (self.check0(l[0]) and self.check1(l[1])):
                        return False
            else:
                if not self.check0(n):
                    return False
            # l=n.split('.')
            # if len(l)>2:
            #     return False
            # if len(l)
        return True

    def check0(l):
        pass
    def check1(l):
        pass


                