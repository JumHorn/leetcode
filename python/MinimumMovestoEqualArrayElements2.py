#coding=uft-8
class MinimumMovestoEqualArrayElements2(object):
    def minMoves2(self,nums):
        """
        :type nums: List[int]
        :rtype: int
        """
<<<<<<< HEAD
        #nums排序，中间的数，是最后的结果,数组长度是奇数就是中间的数，数组长度是偶数，是两个数的平均值
        nums.sort()
        l=len(nums)
        # if len(nums)%2==1:
        #     n=nums[len(nums)//2]
        # else:
        #     n=(nums[len(nums)//2]+nums[len(nums)//2-1])//2
        return sum(nums[l//2+l%2:])-sum(nums[0:l//2])
=======
        #每次计算平均数，计算与平均数振幅
>>>>>>> af11f2fb0552c11afefa374d4f5ca82c45226017
