#coding=utf8
import string
class KthSmallestinLexicographicalOrder(object):
    def findKthNumber(self,n,k):
        """
        :type n:int 
        :type k:int
        :rtype:int
        """
        i=0
        j=0
        l=range(1,n+1)
        while i<k-1:
            j=n-1
            while j>i:
                if cmp(str(l[j]),str(l[j-1]))==-1:
                    temp=l[j]
                    l[j]=l[j-1]
                    l[j-1]=temp
                # print l
                j-=1
            i+=1
        return l[i]

#这个例子要跑十几秒！！！
n=10000
k=9999
K=KthSmallestinLexicographicalOrder()
print K.findKthNumber(n,k)
