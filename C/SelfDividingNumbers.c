#include <stdbool.h>
#include <stdlib.h>

bool selfDividing(int n)
{
	int num = n;
	while (num != 0)
	{
		int d = num % 10;
		if (d == 0 || n % d != 0)
			return false;
		num /= 10;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize)
{
	int* res = (int*)malloc(sizeof(int) * 500);
	*returnSize = 0;
	for (int i = left; i <= right; ++i)
	{
		if (selfDividing(i))
			res[(*returnSize)++] = i;
	}
	return res;
}
