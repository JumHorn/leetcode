class HouseRobber(object):
    def rob(self,nums):
        """
        :type nums: List[int]
        :rtype: int

        #this is a dynamic planning question!this kind of question is easy if you begin with 123
        """
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return nums[0]
        if len(nums)==2:
            if nums[0]>nums[1]:
                return nums[0]
            else:
                return nums[1]
        money=[]
        money.append(nums[0])
        if nums[0]>nums[1]:
            money.append(nums[0])
        else:
            money.append(nums[1])
        i=2
        while i<len(nums):
            if money[i-1]>money[i-2]+nums[i]:
                money.append(money[i-1])
            else:
                money.append(money[i-2]+nums[i])
            i+=1
        return money[len(nums)-1]