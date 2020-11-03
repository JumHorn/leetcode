#include <stdbool.h>
#include <stdlib.h>

bool noZero(int n)
{
	while (n != 0)
	{
		if (n % 10 == 0)
			return false;
		n /= 10;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getNoZeroIntegers(int n, int *returnSize)
{
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 1; i <= n / 2; ++i)
	{
		if (noZero(i) && noZero(n - i))
		{
			res[0] = i;
			res[1] = n - i;
			break;
		}
	}
	return res;
}
