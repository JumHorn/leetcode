#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes)
{
	int N = strlen(s);
	int** res = (int**)malloc(sizeof(int*) * N);
	*returnSize = 0;
	for (int i = 0, j = 0; i <= N; ++i)
	{
		if (i == N || s[i] != s[j])
		{
			if (i - j >= 3)
			{
				res[*returnSize] = (int*)malloc(sizeof(int) * 2);
				res[*returnSize][0] = j;
				res[*returnSize][1] = i - 1;
				++*returnSize;
			}
			j = i;
		}
	}
	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = 2;
	return res;
}
