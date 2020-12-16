#include <limits.h>
#include <string.h>

typedef struct pair
{
	int value;
	int row;
} pair;

//max heap function series
void push_heap(pair *ptr, int size)
{
	if (size <= 1)
		return;
	pair val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.value < ptr[i].value; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(pair *ptr, int size)
{
	if (size <= 0)
		return;
	pair val = *ptr;
	int non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1].value < ptr[i].value)
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = ptr[size - 1];
	push_heap(ptr, hole + 1);
	ptr[size - 1] = val;
}

void make_heap(pair *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

int kthSmallest(int **matrix, int matrixSize, int *matrixColSize, int k)
{
	int M = matrixSize, N = *matrixColSize, heapSize = 0;
	pair heap[M * N];
	for (int i = 0; i < M; ++i)
	{
		heap[heapSize].value = matrix[i][0];
		heap[heapSize].row = i;
		push_heap(heap, ++heapSize);
	}
	int index[M]; //record col index
	memset(index, 0, sizeof(index));
	int res = 0;
	while (--k >= 0)
	{
		res = heap[0].value;
		int i = heap[0].row;
		pop_heap(heap, heapSize--);
		if (++index[i] < N)
		{
			heap[heapSize].value = matrix[i][index[i]];
			heap[heapSize].row = i;
			push_heap(heap, ++heapSize);
		}
	}
	return res;
}