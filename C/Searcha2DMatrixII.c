#include <stdbool.h>

bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target)
{
	if (matrixRowSize == 0)
		return false;
	for (int i = 0, j = matrixColSize - 1; i < matrixRowSize && j >= 0;)
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