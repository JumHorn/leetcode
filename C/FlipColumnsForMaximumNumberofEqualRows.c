#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int arrayEquals(int *arr1, int *arr2, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr1[i] != arr2[i])
			return 0;
	}
	return 1;
}

void arrayFlip(int *arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] ^= 1;
}

int maxEqualRowsAfterFlips(int **matrix, int matrixSize, int *matrixColSize)
{
	//normalise for first ele in row is 1 then flip all row
	int M = matrixSize, N = *matrixColSize;
	for (int i = 0; i < M; ++i)
	{
		if (matrix[i][0] == 1)
			arrayFlip(matrix[i], N);
	}
	int res = 1;
	for (int i = 0; i < M - 1; ++i)
	{
		int same = 1;
		for (int j = i + 1; j < M; ++j)
			same += arrayEquals(matrix[i], matrix[j], N);
		res = max(res, same);
	}
	return res;
}