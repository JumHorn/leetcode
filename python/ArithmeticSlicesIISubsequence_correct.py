#coding=utf8
class ArithmeticSlicesIISubsequence(object):
    def numberOfArithmeticSlices(self,A):
        '''这里使用动态规划的思路dp
           将每个数与前面所有的数的diff生成字典
           每有新diff相同，就是一个等差数列
        '''
        sum=0
        dic=[{} for _ in A] #生成A长度的list内容是字典
        for i in xrange(len(A)):
            for j in xrange(i):
                diff=A[i]-A[j]
                dic[i][diff]=dic[i].get(diff,0)+1
                if diff in dic[j]:
                    sum+=dic[j][diff]
                    dic[i][diff]+=dic[j][diff]
        return sum

A=[2,2,3,4,5]
Ar=ArithmeticSlicesIISubsequence()
print Ar.numberOfArithmeticSlices(A)