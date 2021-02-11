
void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
	int row = 0, M = matrixSize, N = *matrixColSize;
	for (int i = 0; i < M; ++i)
	{
		if (matrix[i][0] == 0)
			row = 1;
		for (int j = 1; j < N; ++j)
		{
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
	}

	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = 1; j < N; ++j)
		{
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
		if (row == 1)
			matrix[i][0] = 0;
	}
}