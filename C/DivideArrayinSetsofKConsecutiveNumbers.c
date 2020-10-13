#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

bool isPossibleDivide(int *nums, int numsSize, int k)
{
	if (numsSize % k != 0)
		return false;
	qsort(nums, numsSize, sizeof(int), cmp);
	int arr[numsSize][2], arrSize = 0; //{val,count}
	for (int i = 1, j = 0; i <= numsSize; ++i)
	{
		if (i == numsSize || nums[i] != nums[j])
		{
			arr[arrSize][0] = nums[j];
			arr[arrSize][1] = i - j;
			j = i;
			++arrSize;
		}
	}
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i][1] == 0)
			continue;
		int count = arr[i][1];
		if (i + k - 1 >= arrSize)
			return false;
		for (int j = 0; j < k; ++j)
		{
			if (arr[i + j][0] - arr[i][0] != j) //consecutive
				return false;
			arr[i + j][1] -= count;
			if (arr[i + j][1] < 0)
				return false;
		}
	}
	return true;
}