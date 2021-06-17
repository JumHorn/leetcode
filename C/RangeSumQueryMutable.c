#include <stdlib.h>
#include <string.h>

//Fenwick tree(BIT)
int sum(int *tree, int size, int index)
{
	int res = 0;
	for (; index > 0; index -= index & -index)
		res += tree[index];
	return res;
}

void update(int *tree, int size, int index, int delta)
{
	for (; index < size; index += index & -index)
		tree[index] += delta;
}
/********end of Fenwick tree(BIT)********/

typedef struct
{
	int *data;
	int size;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
	NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
	obj->size = numsSize + 1;
	obj->data = (int *)malloc(sizeof(int) * obj->size);
	memset(obj->data, 0, sizeof(int) * obj->size);
	for (int i = 0; i < numsSize; ++i)
		update(obj->data, obj->size, i + 1, nums[i]);
	return obj;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
	return sum(obj->data, obj->size, j + 1) - sum(obj->data, obj->size, i);
}

void numArrayUpdate(NumArray *obj, int i, int val)
{
	int delta = val - numArraySumRange(obj, i, i);
	update(obj->data, obj->size, i + 1, delta);
}

void numArrayFree(NumArray *obj)
{
	if (obj)
	{
		if (obj->data)
			free(obj->data);
		free(obj);
	}
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, i, val);

 * int param_2 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/