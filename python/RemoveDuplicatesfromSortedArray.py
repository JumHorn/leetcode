class RemoveDuplicatefromSortedArray(object):
    def removeDuplicatefromSortedArray(self,nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return 1
        i=1
        while i<len(nums):
            if nums[i]==nums[i-1]:
                del nums[i]
                continue
            i+=1
        return len(nums)