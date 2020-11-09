#include <limits.h>
#include <string.h>

/*
radix sort
*/

int maximumGap(int *nums, int numsSize)
{
	if (numsSize < 2)
		return 0;
	int maxval = INT_MIN;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > maxval)
			maxval = nums[i];
	}
	int count[10], base = 1;
	for (int base = 1; maxval / base > 0; base *= 10)
	{
		memset(count, 0, sizeof(count));
		for (int i = 0; i < numsSize; ++i)
			++count[nums[i] / base % 10];
		for (int i = 1; i < 10; ++i)
			count[i] += count[i - 1];
		int aux[numsSize];
		for (int i = numsSize - 1; i >= 0; --i)
			aux[--count[nums[i] / base % 10]] = nums[i];
		memcpy(nums, aux, sizeof(aux));
	}
	int res = 0;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] - nums[i - 1] > res)
			res = nums[i] - nums[i - 1];
	}
	return res;
}