#include <limits.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

void addTriplet(int (*triples)[4], int *size, int a, int b, int c, int d)
{
	// res = (int **)realloc(res, sizeof(int *) * (1 + *size));
	// res[*size] = (int *)malloc(sizeof(int) * 3);
	triples[*size][0] = a;
	triples[*size][1] = b;
	triples[*size][2] = c;
	triples[*size][3] = d;
	++*size;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
	static int triples[30000][4];
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int m = 0, mpre = INT_MIN; m < numsSize - 3; mpre = nums[m++])
	{
		if (nums[m] == mpre)
			continue;
		for (int i = m + 1, pre = INT_MIN; i < numsSize - 2; pre = nums[i++])
		{
			if (nums[i] == pre)
				continue;
			//twoSum(nums, numsSize, i + 1, -nums[i]);
			int j = i + 1, k = numsSize - 1;
			while (j < k)
			{
				int sum = nums[m] + nums[i] + nums[j] + nums[k];
				if (sum == target)
				{
					addTriplet(triples, returnSize, nums[m], nums[i], nums[j], nums[k]);

					++j;
					while (j < k && nums[j] == nums[j - 1])
						++j;
				}
				else if (sum < target)
					++j;
				else
					--k;
			}
		}
	}
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * 4);
		memcpy(res[i], triples[i], sizeof(int) * 4);
		(*returnColumnSizes)[i] = 4;
	}
	return res;
}