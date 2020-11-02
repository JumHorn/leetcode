from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        top = 0
        for n in nums:
            if n != nums[top]:
                top += 1
                nums[top] = n
        return top + 1
