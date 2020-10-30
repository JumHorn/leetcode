#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize)
{
	int hash[bound + 1];
	memset(hash, 0, sizeof(hash));
	int* res = (int*)malloc(sizeof(int) * 2000);
	*returnSize = 0;
	for (int i = 1; i <= bound; i *= x)
	{
		for (int j = 1; j <= bound; j *= y)
		{
			if (i + j <= bound)
				hash[i + j] = 1;
			if (y == 1)
				break;
		}
		if (x == 1)
			break;
	}
	for (int i = 0; i <= bound; ++i)
	{
		if (hash[i] == 1)
			res[(*returnSize)++] = i;
	}
	return res;
}
