#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
	if (matrixSize == 0 || *matrixColSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	*returnSize = matrixSize * (*matrixColSize);
	int *res = (int *)malloc(sizeof(int) * (*returnSize));

	int range[] = {0, *matrixColSize, 0, matrixSize}; //left,right,bottom,top
	int i = 0, j = 0, d = 0;
	int path[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	int rangechange[][4] = {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, -1, 0, 0}, {0, 0, 0, -1}};
	for (int k = 0; k < *returnSize; ++k)
	{
		res[k] = matrix[i][j];
		int dx = i + path[d][0], dy = j + path[d][1];
		if (dx >= range[2] && dx < range[3] && dy >= range[0] && dy < range[1])
		{
			i = dx;
			j = dy;
		}
		else
		{
			d = (d + 1) % 4;
			i += path[d][0];
			j += path[d][1];
			for (int i = 0; i < 4; ++i)
				range[i] += rangechange[d][i];
		}
	}
	return res;
}