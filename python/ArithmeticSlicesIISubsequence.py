#coding=utf8
#这道题一开始默认数组是等差数列，所以计算的是数组中等差数列的个数
class ArithmeticSlicesIISubsequence(object):
    def numberOfArithmeticSlices(self,A):
        n=len(A)
        if n<=2:
            return 0
        else:
            if A[1]-A[0]==0:
                return pow(2,n)-(n+1+n*(n-1)/2)
            else:
                if n==3:
                    return 1
                else:
                    k=3
                    sum=0
                    while k<=n//2+1:
                        i=1
                        while i<=(n-k)//(k-1):
                            sum+=n+1-(k-1)*i-k
                            i+=1
                        k+=1
                    return (n-1)*(n-2)/2+sum

A=[1,2,3,4,5,6,7]
Ar=ArithmeticSlicesIISubsequence()
print Ar.numberOfArithmeticSlices(A)