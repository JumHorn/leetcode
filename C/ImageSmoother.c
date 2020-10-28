#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **imageSmoother(int **M, int MSize, int *MColSize, int *returnSize, int **returnColumnSizes)
{
	int m = MSize, n = *MColSize;
	int **res = mallocRes(M, MSize, MColSize, returnSize, returnColumnSizes);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int gray = 0, count = 0;
			for (int k = max(0, i - 1); k <= min(m - 1, i + 1); ++k)
			{
				for (int l = max(0, j - 1); l <= min(n - 1, j + 1); ++l)
				{
					++count;
					gray += M[k][l];
				}
			}
			res[i][j] = gray / count;
		}
	}
	return res;
}