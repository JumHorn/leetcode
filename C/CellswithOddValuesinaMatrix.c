#include <stdlib.h>
#include <string.h>

int oddCells(int n, int m, int **indices, int indicesSize, int *indicesColSize)
{
	int row[n], col[m];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int k = 0; k < indicesSize; ++k)
	{
		++row[indices[k][0]];
		++col[indices[k][1]];
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ((row[i] + col[j]) % 2 == 1)
				++res;
		}
	}
	return res;
}