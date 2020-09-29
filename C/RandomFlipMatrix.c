#include <stdlib.h>
#include <string.h>

typedef struct
{
	int row;
	int col;
	int total;
	int* data;
} Solution;

Solution* solutionCreate(int n_rows, int n_cols)
{
	Solution* res = (Solution*)malloc(sizeof(Solution));
	res->row = n_rows;
	res->col = n_cols;
	res->total = n_rows * n_cols;
	res->data = (int*)malloc(sizeof(int) * res->total);
	memset(res->data, -1, sizeof(int) * res->total);
	return res;
}

int* solutionFlip(Solution* obj, int* retSize)
{
	*retSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*retSize));
	int i = rand() % obj->total--, index = i;
	if (obj->data[i] != -1)
		index = obj->data[i];
	obj->data[i] = obj->total;
	if (obj->data[obj->total] != -1)
		obj->data[i] = obj->data[obj->total];
	obj->data[obj->total] = index;
	res[0] = index / obj->col;
	res[1] = index % obj->col;
	return res;
}

void solutionReset(Solution* obj)
{
	obj->total = obj->row * obj->col;
}

void solutionFree(Solution* obj)
{
	if (obj)
	{
		if (obj->data)
			free(obj->data);
		free(obj);
	}
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(n_rows, n_cols);
 * int* param_1 = solutionFlip(obj, retSize);
 
 * solutionReset(obj);
 
 * solutionFree(obj);
*/
