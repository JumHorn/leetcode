#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int findLHS(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int arr[numsSize][2], arrSize = 0;  //{value,count}
	for (int i = 0, j = 0; i <= numsSize; ++i)
	{
		if (i == numsSize || nums[i] != nums[j])
		{
			arr[arrSize][0] = nums[j];
			arr[arrSize][1] = i - j;
			++arrSize;
			j = i;
		}
	}
	int res = 0;
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i][0] - arr[i - 1][0] == 1)
			res = max(res, arr[i][1] + arr[i - 1][1]);
	}
	return res;
}
