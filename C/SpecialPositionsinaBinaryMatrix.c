#include <string.h>

int numSpecial(int** mat, int matSize, int* matColSize)
{
	int res = 0, M = matSize, N = *matColSize;
	int row[M], col[N];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mat[i][j] == 1)
			{
				++row[i];
				++col[j];
			}
		}
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
				++res;
		}
	}
	return res;
}
