class RotateFunction(object):
    def maxRotateFunction(self,A):
        if not A:
            return 0
        i=0
        max=-2147483649
        while i<len(A):
            sum=0
            for j,n in enumerate(A):
                sum=sum+j*n
            if sum>max:
                max=sum
            A.insert(0,A[-1])
            A.pop()
            i=i+1
        return max

R=RotateFunction()
print R.maxRotateFunction([1,0,0,0,0,0,0,0,0,7])

# simple Solution
'''
class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        sumA, l = sum(A), len(A)
        temp_sum = sum([i * n for i, n in enumerate(A)])
        max_sum = temp_sum
        for v in A[:-1]:
            temp_sum = temp_sum -sumA + l * v
            if temp_sum > max_sum:
                max_sum = temp_sum
        return max_sum
'''