import sys
class ThirdMaximumNumber(object):
    def thirdMax(self,nums):
        l=[-2147483649,-2147483649,-2147483649]
        for n in nums:
            if n==l[0] or n==l[1] or n==l[2]:
                continue
            if n>l[2]:
                l[0]=l[1]
                l[1]=l[2]
                l[2]=n
            elif n>l[1]:
                l[0]=l[1]
                l[1]=n
            elif n>l[0]:
                l[0]=n
        if l[0]==l[1] or l[1]==l[2]:
            return l[2]
        elif l[0]==-2147483649:
            return l[2]
        else:
            return l[0]


