#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//min heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val < ptr[i]; i = (hole - 1) >> 1)
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
		if (ptr[i - 1] < ptr[i])
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
/********end of min heap********/

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs > *(int *)rhs ? -1 : 1;
}

int maxPerformance(int n, int *speed, int speedSize, int *efficiency, int efficiencySize, int k)
{
	static const int MOD = 1e9 + 7;
	int arr[n][2]; //{efficiency,speed}
	for (int i = 0; i < n; ++i)
	{
		arr[i][0] = efficiency[i];
		arr[i][1] = speed[i];
	}
	qsort(arr, n, sizeof(arr[0]), cmp); //descending
	long res = 0, sum = 0;
	int heap[n], heapSize = 0;
	for (int i = 0; i < n; ++i)
	{
		heap[heapSize++] = arr[i][1];
		push_heap(heap, heapSize);
		sum += arr[i][1];
		if (heapSize > k)
		{
			sum -= heap[0];
			pop_heap(heap, heapSize--);
		}
		res = max(res, arr[i][0] * sum);
	}
	return res % MOD;
}