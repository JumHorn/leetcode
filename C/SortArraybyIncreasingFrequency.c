#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = (int *)lhs, *r = (int *)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return r[1] - l[1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *frequencySort(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	int arr[numsSize][2], arrSize = 0;  //{freq,num}
	int count[201] = {0};
	for (int i = 0; i < numsSize; ++i)
		++count[nums[i] + 100];
	for (int i = 0; i <= 200; ++i)
	{
		if (count[i] != 0)
		{
			arr[arrSize][0] = count[i];
			arr[arrSize][1] = i - 100;
			++arrSize;
		}
	}
	qsort(arr, arrSize, sizeof(arr[0]), cmp);
	for (int i = 0, j = 0; i < arrSize; ++i)
	{
		while (--arr[i][0] >= 0)
			nums[j++] = arr[i][1];
	}
	return nums;
}
