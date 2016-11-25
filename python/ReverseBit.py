import math
class ReverseBits:
    def reverseBits(self,n):
        l=[]
        while n!=0:
            l.append(n%2)
            n=n//2
        l.reverse()
        j=pow(2,32-len(l))
        sum=0
        for m in l:
            sum=sum+j*m
            j=j*2
        return sum 

R=ReverseBits()
print R.reverseBits(2)
