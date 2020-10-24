#include <stdlib.h>

typedef struct
{
	int* prefixsum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize)
{
	NumArray* arr = (NumArray*)malloc(sizeof(NumArray));
	arr->prefixsum = (int*)malloc(sizeof(int) * (numsSize + 1));
	for (int i = 0; i < numsSize; ++i)
		arr->prefixsum[i + 1] = arr->prefixsum[i] + nums[i];
	return arr;
}

int numArraySumRange(NumArray* obj, int i, int j)
{
	return obj->prefixsum[j + 1] - obj->prefixsum[i];
}

void numArrayFree(NumArray* obj)
{
	if (obj)
	{
		if (obj->prefixsum)
			free(obj->prefixsum);
		free(obj);
	}
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
