#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
	if (matrixSize == 0)
		return false;
	for (int i = 0, j = *matrixColSize - 1; i < matrixSize && j >= 0;)
	{
		if (matrix[i][j] == target)
			return true;
		if (matrix[i][j] < target)
			++i;
		else
			--j;
	}
	return false;
}
