#include <stdlib.h>

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

typedef struct
{
	int high[10000];
	int highSize;
	int low[10000];
	int lowSize;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder *medianFinderCreate()
{
	MedianFinder *median = (MedianFinder *)malloc(sizeof(MedianFinder));
	median->highSize = median->lowSize = 0;
	return median;
}

void medianFinderAddNum(MedianFinder *obj, int num)
{
	if (obj->lowSize > obj->highSize)
	{
		obj->high[obj->highSize++] = -num;
		push_heap(obj->high, obj->highSize);
	}
	else
	{
		obj->low[obj->lowSize++] = num;
		push_heap(obj->low, obj->lowSize);
	}
	if (obj->highSize != 0 && obj->low[0] > -obj->high[0])
	{
		int h = -obj->high[0], l = obj->low[0];
		pop_heap(obj->high, obj->highSize--);
		pop_heap(obj->low, obj->lowSize--);

		obj->high[obj->highSize++] = -l;
		push_heap(obj->high, obj->highSize);
		obj->low[obj->lowSize++] = h;
		push_heap(obj->low, obj->lowSize);
	}
}

double medianFinderFindMedian(MedianFinder *obj)
{
	if (obj->lowSize > obj->highSize)
		return obj->low[0];
	return (obj->low[0] - obj->high[0]) / 2.0;
}

void medianFinderFree(MedianFinder *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);

 * double param_2 = medianFinderFindMedian(obj);

 * medianFinderFree(obj);
*/