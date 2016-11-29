#coding=UTF-8
class FactorialTrailingZeroes(object):
    def trailingZeroes(self,n):
        """
        :type n: int
        :rtype: int
        """
        sum=0    #统计这些数中5的个数'
        while n!=0:
            n=n//5
            sum+=n
        return sum