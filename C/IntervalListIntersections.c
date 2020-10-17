#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

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
/********malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **intervalIntersection(int **A, int ASize, int *AColSize, int **B, int BSize, int *BColSize, int *returnSize, int **returnColumnSizes)
{
	if (ASize == 0 || BSize == 0)
	{
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}
	int res[ASize + BSize][2], resColSize[ASize + BSize], resSize = 0;
	int i = 0, j = 0;
	while (i < ASize && j < BSize)
	{
		if (A[i][0] <= B[j][1] && B[j][0] <= A[i][1])
		{
			res[resSize][0] = max(A[i][0], B[j][0]);
			res[resSize][1] = min(A[i][1], B[j][1]);
			resColSize[resSize++] = 2;
		}
		A[i][1] <= B[j][1] ? ++i : ++j;
	}
	return mallocRes(res, resSize, resColSize, returnSize, returnColumnSizes);
}