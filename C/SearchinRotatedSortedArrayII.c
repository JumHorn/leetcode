#include <limits.h>
#include <stdbool.h>

bool search(int *nums, int numsSize, int target)
{
	int lo = 0, hi = numsSize - 1;
	while (lo <= hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (nums[mi] == target)
			return true;
		if (nums[lo] == nums[mi]) //skip duplicates
			++lo;
		else if (nums[lo] < nums[mi])
		{
			if (target >= nums[lo] && target < nums[mi])
				hi = mi - 1;
			else
				lo = mi + 1;
		}
		else
		{
			if (target <= nums[hi] && target > nums[mi])
				lo = mi + 1;
			else
				hi = mi - 1;
		}
	}
	return false;
}