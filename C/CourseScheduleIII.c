#include <stdlib.h>
#include <string.h>

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

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int scheduleCourse(int **courses, int coursesSize, int *coursesColSize)
{
	qsort(courses, coursesSize, sizeof(int *), cmp);
	int heap[coursesSize], heapSize = 1;
	int time = heap[0] = courses[0][0];
	for (int i = 1; i < coursesSize; ++i)
	{
		if (time + courses[i][0] <= courses[i][1])
		{
			time += courses[i][0];
			heap[heapSize++] = courses[i][0];
			push_heap(heap, heapSize);
		}
		else
		{
			if (courses[i][0] < heap[0])
			{
				time += courses[i][0] - heap[0];
				pop_heap(heap, heapSize--);
				heap[heapSize++] = courses[i][0];
				push_heap(heap, heapSize);
			}
		}
	}
	return heapSize;
}