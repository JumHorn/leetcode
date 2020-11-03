
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
	//vertival flip
	for (int i = 0; i < matrixSize / 2; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
			swap(matrix[i][j], matrix[matrixSize - i - 1][j]);
	}
	//diagonal flip
	for (int i = 0; i < matrixSize - 1; ++i)
	{
		for (int j = i + 1; j < matrixSize; ++j)
			swap(matrix[i][j], matrix[j][i]);
	}
}