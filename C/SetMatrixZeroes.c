

void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
	int first_row = 0, first_col = 0, M = matrixSize, N = *matrixColSize;

	for (int i = 0; i < M; ++i)
	{
		if (matrix[i][0] == 0)
		{
			first_col = 1;
			break;
		}
	}

	for (int j = 0; j < N; ++j)
	{
		if (matrix[0][j] == 0)
		{
			first_row = 1;
			break;
		}
	}

	for (int i = 1; i < M; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
		}
	}

	for (int i = 1; i < M; ++i)
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 0; j < N; ++j)
				matrix[i][j] = 0;
		}
	}

	for (int j = 1; j < N; ++j)
	{
		if (matrix[0][j] == 0)
		{
			for (int i = 0; i < M; ++i)
				matrix[i][j] = 0;
		}
	}

	if (first_row == 1)
	{
		for (int j = 0; j < N; ++j)
			matrix[0][j] = 0;
	}
	if (first_col == 1)
	{
		for (int i = 0; i < M; ++i)
			matrix[i][0] = 0;
	}
}
