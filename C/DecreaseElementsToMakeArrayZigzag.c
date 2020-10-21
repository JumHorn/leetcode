#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int movesToMakeZigzag(int* nums, int numsSize)
{
	int res[2] = {0};
	for (int i = 0; i < numsSize; ++i)
	{
		int left = i > 0 ? nums[i - 1] : INT_MAX;
		int right = i + 1 < numsSize ? nums[i + 1] : INT_MAX;
		res[i % 2] += max(0, nums[i] - min(left, right) + 1);
	}
	return min(res[0], res[1]);
}
