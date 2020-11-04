#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int x, int y)
{
	if (x == 0)
		return y;
	return gcd(y % x, x);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** simplifiedFractions(int n, int* returnSize)
{
	char** res = (char**)malloc(sizeof(char*) * n * 50);
	*returnSize = 0;
	char fraction[10];
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (gcd(j, i) == 1)
			{
				sprintf(fraction, "%d/%d", j, i);
				res[(*returnSize)++] = strdup(fraction);
			}
		}
	}
	return res;
}
