#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int *mallocRes(int a, int b, int *returnSize)
{
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * 2);
	res[0] = a;
	res[1] = b;
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	*returnSize = 2;
	int arr[numsSize][2]; //{value,index}
	for (int i = 0; i < numsSize; ++i)
	{
		arr[i][0] = nums[i];
		arr[i][1] = i;
	}
	qsort(arr, numsSize, sizeof(arr[0]), cmp);
	int i = 0, j = numsSize - 1;
	while (i < j)
	{
		if (arr[i][0] + arr[j][0] == target)
			return mallocRes(arr[i][1], arr[j][1], returnSize);
		if (arr[i][0] + arr[j][0] < target)
			++i;
		else
			--j;
	}
	*returnSize = 0;
	return NULL;
}