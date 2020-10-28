#include <stdlib.h>

//min heap function series
void push_heap(int *ptr, int size)
{
	if (size <= 1)
		return;
	int val = ptr[size - 1], hole = size - 1;
	for (int i = (hole - 1) >> 1; hole > 0 && val<ptr[i]; i = (hole - 1)>> 1)
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

typedef struct
{
	int size;
	int capacity;
	int *data;
} KthLargest;

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
	KthLargest *kthlargest = (KthLargest *)malloc(sizeof(KthLargest));
	kthlargest->capacity = k;
	kthlargest->size = 0;
	kthlargest->data = (int *)malloc(sizeof(int) * kthlargest->capacity);
	for (int i = 0; i < numsSize; ++i)
		kthLargestAdd(kthlargest, nums[i]);
	return kthlargest;
}

int kthLargestAdd(KthLargest *obj, int val)
{
	if (obj->size < obj->capacity)
	{
		obj->data[obj->size++] = val;
		push_heap(obj->data, obj->size);
	}
	else if (obj->data[0] < val)
	{
		pop_heap(obj->data, obj->size);
		obj->data[obj->size - 1] = val;
		push_heap(obj->data, obj->size);
	}
	return obj->data[0];
}

void kthLargestFree(KthLargest *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/