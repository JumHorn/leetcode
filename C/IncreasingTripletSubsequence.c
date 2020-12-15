#include <limits.h>
#include <stdbool.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

bool increasingTriplet(int *nums, int numsSize)
{
	int one = INT_MAX, two = INT_MAX;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > two)
			return true;
		if (nums[i] > one)
			two = nums[i];
		else
			one = min(one, nums[i]);
	}
	return false;
}