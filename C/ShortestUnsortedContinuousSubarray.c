#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int findUnsortedSubarray(int* nums, int numsSize)
{
	int maxleft = nums[0], minright = nums[numsSize - 1];
	int left = 1, right = 0;
	for (int i = 1; i < numsSize; ++i)
	{
		maxleft = max(maxleft, nums[i]);
		minright = min(minright, nums[numsSize - 1 - i]);
		if (nums[i] < maxleft)
			right = i;
		if (nums[numsSize - 1 - i] > minright)
			left = numsSize - 1 - i;
	}
	return right - left + 1;
}
