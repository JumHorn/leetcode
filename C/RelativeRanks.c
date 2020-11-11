#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findRelativeRanks(int *nums, int numsSize, int *returnSize)
{
	int arr[numsSize][2]; //{score,index}
	for (int i = 0; i < numsSize; ++i)
	{
		arr[i][0] = nums[i];
		arr[i][1] = i;
	}
	qsort(arr, numsSize, sizeof(arr[0]), cmp); //descending
	char *winner[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
	*returnSize = numsSize;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (char *)malloc(sizeof(char) * sizeof("Bronze Medal"));
	for (int i = 0; i < min(3, numsSize); ++i)
		strcpy(res[arr[i][1]], winner[i]);
	for (int i = 3; i < numsSize; ++i)
		sprintf(res[arr[i][1]], "%d", i + 1);
	return res;
}