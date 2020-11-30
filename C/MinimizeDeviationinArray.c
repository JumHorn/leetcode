#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

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

int minimumDeviation(int *nums, int numsSize)
{
	int heap[numsSize], heapSize = 0;
	int lower = INT_MAX, upper = INT_MIN, res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] & 1) //odd value can only multi once
			nums[i] <<= 1;
		heap[heapSize++] = nums[i];
		push_heap(heap, heapSize);
		lower = min(lower, nums[i]);
		upper = max(upper, nums[i]);
	}
	res = upper - lower;
	while (heap[0] % 2 == 0)
	{
		upper = heap[0];
		res = min(res, upper - lower);
		pop_heap(heap, heapSize--);
		upper >>= 1;
		lower = min(lower, upper);
		heap[heapSize++] = upper;
		push_heap(heap, heapSize);
	}
	return min(res, heap[0] - lower);
}