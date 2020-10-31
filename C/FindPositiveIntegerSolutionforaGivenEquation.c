#include <stdlib.h>
#include <string.h>

/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

//malloc result
int **mallocRes(int (*data)[2], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findSolution(int (*customFunction)(int, int), int z, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][2], staticResColSize[1000];
	*returnSize = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		int lo = customFunction(i, 1), hi = customFunction(i, 1000);
		if (lo > z)
			break;
		if (hi < z)
			continue;
		lo = 1;
		hi = 1000;
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int val = customFunction(i, mi);
			if (val == z)
			{
				staticResColSize[*returnSize] = 2;
				staticRes[*returnSize][0] = i;
				staticRes[*returnSize][1] = mi;
				++*returnSize;
				break;
			}
			if (val < z)
				lo = mi + 1;
			else
				hi = mi - 1;
		}
	}
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}