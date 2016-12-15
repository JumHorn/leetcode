#coding=utf8
class KthSmallestinLexicographicalOrder(object):
    def findKthNumber(self,n,k):
        """
        :type n:int 
        :type k:int
        :rtype:int
        """
        #相比于上一个解法，这里从两段找比较次数少的进行
        if k<=n//2:
            return self.find0(n,k)
        else:
            return self.find1(n,k)
    def find0(self,n,k):
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
    def find1(self,n,k):
        i=n-1
        j=0
        l=range(1,n+1)
        while i>=k-1:
            j=0
            while j<=i-1:
                if cmp(str(l[j]),str(l[j+1]))==1:
                    temp=l[j]
                    l[j]=l[j+1]
                    l[j+1]=temp
                # print l
                j+=1
            i-=1
        return l[i+1]

n=10000
k=9999
K=KthSmallestinLexicographicalOrder()
print K.findKthNumber(n,k)