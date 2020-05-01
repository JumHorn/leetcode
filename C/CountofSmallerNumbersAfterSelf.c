#include <stdlib.h>
#include <string.h>

struct Pair
{
	int val;
	int index;
};

void assign(struct Pair* lhs, struct Pair* rhs)
{
	lhs->val = rhs->val;
	lhs->index = rhs->index;
}

void merge(struct Pair* array, struct Pair* dup, int start, int mid, int end)
{
	int i = start, j = mid, d = 0;
	while (i < mid && j < end)
	{
		if (array[i].val <= array[j].val)
			assign(&dup[d++], &array[i++]);
		else
			assign(&dup[d++], &array[j++]);
	}
	while (i < mid)
		assign(&dup[d++], &array[i++]);
	while (j < end)
		assign(&dup[d++], &array[j++]);
	for (i = 0; i < d; i++)
		assign(&array[start + i], &dup[i]);
}

void divide(struct Pair* array, struct Pair* dup, int start, int end, int* res)
{
	if (end - start <= 1)
		return;
	int mid = (end - start) / 2 + start;
	divide(array, dup, start, mid, res);
	divide(array, dup, mid, end, res);
	for (int i = start, j = mid; i < mid; i++)
	{
		while (j < end && array[i].val > array[j].val)
			++j;
		res[array[i].index] += j - mid;
	}
	merge(array, dup, start, mid, end);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	if (numsSize == 0)
		return NULL;
	int* res = (int*)malloc(sizeof(int) * numsSize);
	memset(res, 0, sizeof(int) * numsSize);
	struct Pair array[numsSize], dup[numsSize];
	for (int i = 0; i < numsSize; i++)
	{
		array[i].val = nums[i];
		array[i].index = i;
	}
	divide(array, dup, 0, numsSize, res);
	return res;
}
