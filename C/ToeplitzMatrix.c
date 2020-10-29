#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize)
{
	int M = matrixSize, N = *matrixColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i > 0 && j > 0 && matrix[i - 1][j - 1] != matrix[i][j])
				return false;
		}
	}
	return true;
}
