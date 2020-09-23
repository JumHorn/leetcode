#include <stdlib.h>
#include <string.h>

typedef struct
{
	int** matrix;
	int M;
	int N;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize)
{
	if (matrixSize == 0)
		return NULL;
	NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
	obj->M = matrixSize + 1;
	obj->N = *matrixColSize + 1;
	obj->matrix = (int**)malloc(sizeof(int*) * obj->M);
	for (int i = 0; i < obj->M; ++i)
	{
		obj->matrix[i] = (int*)malloc(sizeof(int) * obj->N);
		memset(obj->matrix[i], 0, sizeof(int) * obj->N);
	}
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < *matrixColSize; ++j)
		{
			obj->matrix[i + 1][j + 1] = obj->matrix[i + 1][j] + obj->matrix[i][j + 1] - obj->matrix[i][j] + matrix[i][j];
		}
	}
	return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
	return obj->matrix[row2 + 1][col2 + 1] - obj->matrix[row2 + 1][col1] - obj->matrix[row1][col2 + 1] + obj->matrix[row1][col1];
}

void numMatrixFree(NumMatrix* obj)
{
	if (obj)
	{
		for (int i = 0; i < obj->M; ++i)
			free(obj->matrix[i]);
		free(obj);
	}
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
