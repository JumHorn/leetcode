#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

bool checkArithmetic(int* arr, int arrSize)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	for (int i = 2; i < arrSize; ++i)
	{
		if (arr[i] - arr[i - 1] != arr[1] - arr[0])
			return false;
	}
	return true;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize)
{
	int N = lSize;
	*returnSize = N;
	bool* res = (bool*)malloc(sizeof(bool) * (*returnSize));
	int arr[numsSize];
	for (int i = 0; i < N; ++i)
	{
		int size = r[i] - l[i] + 1;
		memcpy(arr, &nums[l[i]], sizeof(int) * size);
		res[i] = checkArithmetic(arr, size);
	}
	return res;
}
