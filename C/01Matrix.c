#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memset(res[i], 1 << 6, sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **updateMatrix(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int **returnColumnSizes)
{
	int **dp = mallocRes(matrix, matrixSize, matrixColSize, returnSize, returnColumnSizes);
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < *matrixColSize; ++j)
		{
			if (matrix[i][j] == 0)
				dp[i][j] = 0;
			else
			{
				if (i > 0)
					dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				if (j > 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
		}
	}
	for (int i = matrixSize - 1; i >= 0; --i)
	{
		for (int j = *matrixColSize - 1; j >= 0; --j)
		{
			if (i < matrixSize - 1)
				dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
			if (j < *matrixColSize - 1)
				dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
		}
	}
	return dp;
}
