#include <stdbool.h>

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

bool isGoodArray(int *nums, int numsSize)
{
	int g = nums[0];
	for (int i = 0; i < numsSize; ++i)
	{
		g = gcd(g, nums[i]);
		if (g == 1)
			return true;
	}
	return false;
}