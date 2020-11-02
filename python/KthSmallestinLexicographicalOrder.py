#coding=utf8
class KthSmallestinLexicographicalOrder(object):
    def findKthNumber(self,n,k):
        """
        :type n:int 
        :type k:int
        :rtype:int
        """
        #十叉树的先序遍历，判断1和2之间有多少个数，再对下一位做判断
        k-=1
        left=1
        while k>0:
            num=self.numBetween(n,left)
            if num<=k:
                k-=num
                left+=1
            else:
                left*=10
                k-=1
        return left
    def numBetween(self,n,left):
        num=0
        right=left+1
        while left<=n:
            num+=min(n+1,right)-left
            left*=10
            right*=10
        return num

n=10000
k=9999
K=KthSmallestinLexicographicalOrder()
print K.findKthNumber(n,k)