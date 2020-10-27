#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return **(int **)lhs - **(int **)rhs;
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

int maxEvents(int **events, int eventsSize, int *eventsColSize)
{
	qsort(events, eventsSize, sizeof(int *), cmp);
	int heap[eventsSize], heapSize = 0;
	int res = 0, d = 0;
	for (int i = 0; heapSize != 0 || i < eventsSize;)
	{
		if (heapSize == 0)
			d = events[i][0];
		while (i < eventsSize && events[i][0] <= d)
		{
			heap[heapSize++] = -events[i++][1];
			push_heap(heap, heapSize);
		}
		pop_heap(heap, heapSize--);
		++res;
		++d;
		while (heapSize != 0 && -heap[0] < d)
			pop_heap(heap, heapSize--);
	}
	return res;
}