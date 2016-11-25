import math
class NthDigit(object):
    l=[0]
    def findNthDigit(self,n):
        '''
        :type n:int
        :rtype:int
        '''
        if n<10:
            return n
        k=self.FindInterval(n)
        print "k=",k
        return self.FindNumber(n,k)
    def FindNumber(self,n,k):
        quotient=(n-self.l[k-1])//k
        print "quotient=",quotient
        remainder=(n-self.l[k-1])%k
        print "remainder=",remainder
        num=quotient-1+math.pow(10,k-1)
        if remainder!=0:
            return int((num+1)//math.pow(10,k-remainder)%10)
        else:
            return int(num%10)
    def FindInterval(self,n):
        k=1
        while k<11:
            self.l.append(k*9*math.pow(10,k-1)+self.l[k-1])
            if self.l[k]>n:
                return k
            k=k+1   

N=NthDigit()
print N.findNthDigit(1000)