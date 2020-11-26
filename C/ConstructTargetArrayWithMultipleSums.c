#include <stdbool.h>

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

bool isPossible(int *target, int targetSize)
{
	int heap[targetSize], heapSize = 0;
	long sum = 0;
	for (int i = 0; i < targetSize; ++i)
	{
		heap[heapSize++] = target[i];
		push_heap(heap, heapSize);
		sum += target[i];
	}
	while (heapSize != 0)
	{
		int largest = heap[0];
		pop_heap(heap, heapSize--);
		sum -= largest;
		if (largest == 1 || sum == 1)
			return true;
		if (largest < sum || sum == 0 || largest % sum == 0)
			return false;
		largest %= sum; //for single large element,substract many times
		sum += largest;
		heap[heapSize++] = largest;
		push_heap(heap, heapSize);
	}
	return false;
}