class ExcelSheetColumnTitle(object):
    def convertToTitle(self,n):
        """
        :type n: int
        :rtype: str
        """
        l=[]
        while n!=0:
            if n%26==0:
                l.append('Z')
            else:
                l.append(chr(64+n%26))
            if n%26==0:
                n=n//26-1
                continue
            n=n//26
        l.reverse()
        return ''.join(l)