#include <limits.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct tuple
{
	int val;
	int row;
	int col;
} tuple;

//min heap function series
void push_heap(tuple *ptr, int size)
{
	if (size <= 1)
		return;
	tuple val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.val < ptr[i].val; i = (hole - 1) >> 1)
	{
		ptr[hole] = ptr[i];
		hole = i;
	}
	ptr[hole] = val;
}

void pop_heap(tuple *ptr, int size)
{
	if (size <= 0)
		return;
	tuple val = *ptr;
	int non_leaf = (size - 1) >> 1, hole = 0, i = 0;
	while (i < non_leaf)
	{
		i = 2 * i + 2;
		if (ptr[i - 1].val < ptr[i].val)
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

void make_heap(tuple *ptr, int size)
{
	for (int i = 1; i < size; ++i)
		push_heap(ptr, i + 1);
}
/********end of min heap********/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallestRange(int **nums, int numsSize, int *numsColSize, int *returnSize)
{
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int heapSize = 0, maxval = INT_MIN;
	tuple heap[numsSize], ele;
	for (int i = 0; i < numsSize; ++i)
	{
		maxval = max(maxval, nums[i][0]);
		heap[heapSize].val = nums[i][0];
		heap[heapSize].row = i;
		heap[heapSize].col = 0;
		make_heap(heap, ++heapSize);
	}
	int range = maxval - heap[0].val;
	res[0] = heap[0].val;
	res[1] = maxval;

	while (heap[0].col + 1 < numsColSize[heap[0].row])
	{
		tuple ele = heap[0];
		pop_heap(heap, heapSize--);
		ele.val = nums[ele.row][++ele.col];
		maxval = max(maxval, ele.val);
		heap[heapSize++] = ele;
		push_heap(heap, heapSize);
		if (maxval - heap[0].val < range)
		{
			range = maxval - heap[0].val;
			res[0] = heap[0].val;
			res[1] = maxval;
		}
	}
	return res;
}