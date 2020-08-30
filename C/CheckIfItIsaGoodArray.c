#include <stdbool.h>

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

bool isGoodArray(int* nums, int numsSize)
{
	int last = nums[0];
	for (int i = 0; i < numsSize; ++i)
	{
		last = gcd(last, nums[i]);
		if (last == 1)
			return true;
	}
	return false;
}
