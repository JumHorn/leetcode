#include <limits.h>

int thirdMax(int* nums, int numsSize)
{
	long first, second, third;
	first = second = third = INT_MIN - 1L;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == first || nums[i] == second || nums[i] == third)
			continue;
		if (nums[i] > first)
		{
			third = second;
			second = first;
			first = nums[i];
		}
		else if (nums[i] > second)
		{
			third = second;
			second = nums[i];
		}
		else if (nums[i] > third)
			third = nums[i];
	}
	return third >= INT_MIN ? third : first;
}
