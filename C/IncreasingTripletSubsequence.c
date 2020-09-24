#include <string.h>

bool increasingTriplet(int* nums, int numsSize)
{
	int min, mid, i;
	for (i = 1; i < numsSize; ++i)
	{
		if (nums[i - 1] < nums[i])
			break;
	}
	if (i >= numsSize)
		return false;
	min = nums[i - 1];
	mid = nums[i];
	for (++i; i < numsSize; ++i)
	{
		if (nums[i] > mid)
			return true;
		if (nums[i] < min)
			min = nums[i];
		else if (nums[i] > min && nums[i] < mid)
			mid = nums[i];
	}
	return false;
}
