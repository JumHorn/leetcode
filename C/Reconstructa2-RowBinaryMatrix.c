#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **reconstructMatrix(int upper, int lower, int *colsum, int colsumSize, int *returnSize, int **returnColumnSizes)
{
	int count = 0;
	for (int i = 0; i < colsumSize; ++i)
	{
		if (colsum[i] == 2)
		{
			--upper;
			--lower;
		}
		else if (colsum[i] == 1)
			++count;
	}
	if (upper < 0 || lower < 0 || upper + lower != count)
	{
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}

	*returnSize = 2;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		(*returnColumnSizes)[i] = colsumSize;
		res[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
	}

	for (int i = 0; i < colsumSize; ++i)
	{
		if (colsum[i] == 1)
		{
			if (--upper >= 0)
			{
				res[0][i] = 1;
				res[1][i] = 0;
			}
			else
			{
				res[0][i] = 0;
				res[1][i] = 1;
			}
		}
		else if (colsum[i] == 0)
			res[0][i] = res[1][i] = 0;
		else
			res[0][i] = res[1][i] = 1;
	}
	return res;
}