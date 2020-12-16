#include <string.h>

int countSmallerNumber(int *arr, int arrSize, int value)
{
	int lo = 0, hi = arrSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] <= value)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}

int kthSmallest(int **matrix, int matrixSize, int *matrixColSize, int k)
{
	int M = matrixSize, N = *matrixColSize;
	int lo = matrix[0][0], hi = matrix[M - 1][N - 1];
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo, count = 0;
		for (int i = 0; i < M; ++i)
			count += countSmallerNumber(matrix[i], N, mi);
		if (count < k)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}