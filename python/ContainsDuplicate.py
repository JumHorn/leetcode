#coding=UTF-8
class ContainsDuplicate2(object):
    def containsNearbyDuplicate(self,nums,k):
        '''
        :type nums:List[int]
        :type k:int
        :rtype:bool
        '''
        numDict = dict()#的构造函数,构造的dict是{“值”：“下标”}
        for n in range(len(nums)):
            i = numDict.get(nums[n])
            if i >= 0 and n - i <= k:
                return True
            numDict[nums[n]] = n
        return False       