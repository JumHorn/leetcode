#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **spiralMatrixIII(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes)
{
	*returnSize = R * C;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; i++)
	{
		(*returnColumnSizes)[i] = 2;
		res[i] = (int *)malloc(sizeof(int) * 2);
	}
	int index = 0, radius = 1, x = c0, y = r0, left, right = c0 + radius, top, bottom;
	while (index < (*returnSize))
	{
		//->
		while (x <= right)
		{
			if (x < C && y >= 0 && y < R)
			{
				if (x >= 0)
				{
					res[index][0] = y;
					res[index++][1] = x;
				}
				else
					x = -1;
			}
			else
				x = right;
			++x;
		}
		// v
		bottom = y + radius;
		--x;
		++y;
		while (y <= bottom)
		{
			if (y < R && x >= 0 && x < C)
			{
				if (y >= 0)
				{
					res[index][0] = y;
					res[index++][1] = x;
				}
				else
					y = -1;
			}
			else
				y = bottom;
			++y;
		}
		//<-
		radius++;
		left = x - radius;
		--y;
		--x;
		while (x >= left)
		{
			if (x >= 0 && y >= 0 && y < R)
			{
				if (x < C)
				{
					res[index][0] = y;
					res[index++][1] = x;
				}
				else
					x = C;
			}
			else
				x = left;
			--x;
		}
		//^
		top = y - radius;
		--y;
		++x;
		while (y >= top)
		{
			if (y >= 0 && x >= 0 && x < C)
			{
				if (y < R)
				{
					res[index][0] = y;
					res[index++][1] = x;
				}
				else
					y = R;
			}
			else
				y = top;
			--y;
		}
		++radius;
		right = x + radius;
		++y;
		++x;
	}
	return res;
}