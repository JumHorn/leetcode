
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define trimin(a, b, c) (min(min(a, b), c))  //the minimum of a,b,c

int countSquares(int** matrix, int matrixSize, int* matrixColSize)
{
	int M = matrixSize, N = *matrixColSize;
	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (matrix[i][j] != 0 && i != 0 && j != 0)
				matrix[i][j] += trimin(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]);
			res += matrix[i][j];
		}
	}
	return res;
}
