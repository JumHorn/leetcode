#include <stdbool.h>

bool canJump(int* nums, int numsSize)
{
	int maxright = nums[0];
	for (int i = 0; i <= maxright && maxright < numsSize - 1; ++i)
	{
		if (nums[i] + i > maxright)
			maxright = nums[i] + i;
	}
	return maxright >= numsSize - 1;
}
