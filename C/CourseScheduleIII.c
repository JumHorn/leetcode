#include <stdlib.h>
#include <string.h>

//max heap function series
void push_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = ptr[size - 1], hole = size - 1;
		for (int i = (hole - 1) >> 1; hole > 0 && val > ptr[i]; i = (hole - 1) >> 1)
		{
			ptr[hole] = ptr[i];
			hole = i;
		}
		ptr[hole] = val;
	}
}

//for internal usage
void _adjust_heap(int *ptr, int size, int hole, int val)
{
	int non_leaf = (size - 1) >> 1, i = hole;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i] < ptr[i - 1])
			--i;
		ptr[hole] = ptr[i];
		hole = i;
	}
	if (i == non_leaf && size % 2 == 0)
	{
		ptr[hole] = ptr[size - 1];
		hole = size - 1;
	}
	ptr[hole] = val;
	push_heap(ptr, hole + 1);
}

void make_heap(int *ptr, int size)
{
	for (int hole = (size - 1) >> 1; hole >= 0; --hole)
		_adjust_heap(ptr, size, hole, ptr[hole]);
}

void pop_heap(int *ptr, int size)
{
	if (size > 0)
	{
		int val = *ptr;
		_adjust_heap(ptr, size, 0, ptr[size - 1]);
		ptr[size - 1] = val;
	}
}

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int scheduleCourse(int **courses, int coursesSize, int *coursesColSize)
{
	qsort(courses, coursesSize, sizeof(int *), cmp);
	int size = 1, priorityqueue[coursesSize];
	int time = priorityqueue[0] = courses[0][0];
	for (int i = 1; i < coursesSize; i++)
	{
		if (time + courses[i][0] <= courses[i][1])
		{
			time += courses[i][0];
			priorityqueue[size++] = courses[i][0];
			push_heap(priorityqueue, size);
		}
		else
		{
			if (courses[i][0] < priorityqueue[0])
			{
				time += courses[i][0] - priorityqueue[0];
				pop_heap(priorityqueue, size);
				priorityqueue[size - 1] = courses[i][0];
				push_heap(priorityqueue, size);
			}
		}
	}
	return size;
}