from typing import List


class NumArray:
    def __init__(self, nums: List[int]):
        self.arr = [0]
        for n in nums:
            self.arr.append(self.arr[-1] + n)

    def sumRange(self, i: int, j: int) -> int:
        return self.arr[j + 1] - self.arr[i]

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
