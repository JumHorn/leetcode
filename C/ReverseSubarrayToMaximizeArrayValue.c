#include <stdlib.h>

int maxValueAfterReverse(int *nums, int numsSize)
{
	int res = 0, origin = 0;
	for (int i = 1; i < numsSize; ++i)
		origin += abs(nums[i] - nums[i - 1]);
	res = origin;
	for (int i = 1; i < numsSize - 1; ++i)
	{
		int delta = abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]);
		if (delta > 0 && origin + delta > res)
			res = origin + delta;
		delta = abs(nums[numsSize - 2 - i] - nums[numsSize - 1]);
		delta -= abs(nums[numsSize - 2 - i] - nums[numsSize - 1 - i]);
		if (delta > 0 && origin + delta > res)
			res = origin + delta;
	}
	for (int i = 1; i < numsSize - 2; ++i)
	{
		for (int j = i + 1; j < numsSize - 1; ++j)
		{
			int delta = abs(nums[j] - nums[i - 1]) + abs(nums[j + 1] - nums[i]);
			delta -= abs(nums[i] - nums[i - 1]) + abs(nums[j + 1] - nums[j]);
			if (delta > 0 && origin + delta > res)
				res = origin + delta;
		}
	}
	return res;
}