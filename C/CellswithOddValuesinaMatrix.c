#include <stdlib.h>
#include <string.h>

int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize)
{
	int** matrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		matrix[i] = (int*)malloc(sizeof(int) * m);
		memset(matrix[i], 0, sizeof(int) * m);
	}
	for (int k = 0; k < indicesSize; k++)
	{
		for (int i = 0; i < n; i++)
			matrix[i][indices[k][1]]++;
		for (int j = 0; j < m; j++)
			matrix[indices[k][0]][j]++;
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matrix[i][j] % 2 == 1)
				res++;
	return res;
}

