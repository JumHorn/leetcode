#include <limits.h>
#include <string.h>

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
	int index[matrixSize], res = INT_MAX;
	memset(index, 0, sizeof(index));
	while (--k >= 0)
	{
		res = INT_MAX;
		int j = 0;
		for (int i = 0; i < matrixSize; ++i)
		{
			if (index[i] < *matrixColSize && matrix[i][index[i]] < res)
			{
				res = matrix[i][index[i]];
				j = i;
			}
		}
		++index[j];
	}
	return res;
}
