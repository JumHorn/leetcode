#include <limits.h>
/*
Let's say nums looks like this: [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
[12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

If target is let's say 7, then we adjust nums to this:
[-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
*/

int search(int *nums, int numsSize, int target)
{
	int lo = 0, hi = numsSize - 1;
	while (lo <= hi)
	{
		int mi = (hi - lo) / 2 + lo;
		int num = (nums[mi] < nums[0]) == (target < nums[0]) ? nums[mi] : (target < nums[0] ? INT_MIN : INT_MAX);
		if (num == target)
			return mi;
		if (num < target)
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	return -1;
}