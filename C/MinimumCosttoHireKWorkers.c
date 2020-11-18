#include <limits.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//double cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(double *)lhs == *(double *)rhs)
		return 0;
	return *(double *)lhs < *(double *)rhs ? -1 : 1;
}

//max heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(int *ptr, int size)
{
	if (size <= 0)
		return;
	int val = *ptr, non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1] > ptr[i])
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

void make_heap(int *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of max heap********/

double mincostToHireWorkers(int *quality, int qualitySize, int *wage, int wageSize, int K)
{
	double expect[wageSize][2]; //{exp,quality}
	for (int i = 0; i < qualitySize; ++i)
	{
		expect[i][0] = wage[i] * 1.0 / quality[i];
		expect[i][1] = quality[i];
	}
	qsort(expect, wageSize, sizeof(expect[0]), cmp);
	int heap[K + 1], heapSize = 0; //store workers quality
	double res = INT_MAX, qualitysum = 0.0;
	for (int i = 0; i < qualitySize; ++i)
	{
		qualitysum += expect[i][1];
		heap[heapSize++] = expect[i][1];
		push_heap(heap, heapSize);
		if (heapSize > K)
		{
			qualitysum -= heap[0];
			pop_heap(heap, heapSize--);
		}
		if (heapSize == K)
			res = min(res, qualitysum * expect[i][0]);
	}
	return res;
}