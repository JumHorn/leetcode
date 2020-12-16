#include <stdlib.h>

typedef struct pair
{
	int first;
	int second;
} pair;

//max heap function series
void push_heap(pair *ptr, int size)
{
	if (size <= 1)
		return;
	pair val = ptr[size - 1];
	int hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val.first + val.second > ptr[i].first + ptr[i].second; i = (hole - 1) >> 1)
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
		if (ptr[i - 1].first + ptr[i - 1].second > ptr[i].first + ptr[i].second)
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes)
{
	pair heap[k];
	int heapSize = 0;
	for (int i = 0; i < nums1Size; ++i)
	{
		for (int j = 0; j < nums2Size; ++j)
		{
			if (heapSize >= k)
			{
				if (heap[0].first + heap[0].second <= nums1[i] + nums2[j])
					break;
				pop_heap(heap, heapSize--);
			}
			heap[heapSize].first = nums1[i];
			heap[heapSize].second = nums2[j];
			push_heap(heap, ++heapSize);
		}
	}
	k = k > heapSize ? heapSize : k;

	*returnSize = k;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < k; ++i)
	{
		(*returnColumnSizes)[i] = 2;
		res[k - i - 1] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
		res[k - i - 1][0] = heap[0].first;
		res[k - i - 1][1] = heap[0].second;
		pop_heap(heap, heapSize--);
	}
	return res;
}