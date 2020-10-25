#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sequentialDigits(int low, int high, int* returnSize)
{
	int sequence[] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
	int increase[] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
	int i = 0, value = low;
	while (value != 0)
	{
		++i;
		value /= 10;
	}
	int* res = (int*)malloc(sizeof(int) * 40);
	*returnSize = 0;
	for (; i < 10 && sequence[i] <= high; ++i)
	{
		for (int j = 0; j < 10 - i; ++j)
		{
			value = sequence[i] + increase[i] * j;
			if (value > high)
				break;
			if (value >= low)
				res[(*returnSize)++] = value;
		}
	}
	return res;
}
