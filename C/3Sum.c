#include <limits.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

void addTriplet(int (*triples)[3], int *size, int a, int b, int c)
{
	// res = (int **)realloc(res, sizeof(int *) * (1 + *size));
	// res[*size] = (int *)malloc(sizeof(int) * 3);
	triples[*size][0] = a;
	triples[*size][1] = b;
	triples[*size][2] = c;
	++*size;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int triples[30000][3];
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0, pre = INT_MIN; i < numsSize - 2; pre = nums[i++])
	{
		if (nums[i] == pre)
			continue;
		//twoSum(nums, numsSize, i + 1, -nums[i]);
		int j = i + 1, k = numsSize - 1;
		while (j < k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum == 0)
			{
				addTriplet(triples, returnSize, nums[i], nums[j], nums[k]);

				++j;
				while (j < k && nums[j] == nums[j - 1])
					++j;
			}
			else if (sum < 0)
				++j;
			else
				--k;
		}
	}
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * 3);
		memcpy(res[i], triples[i], sizeof(int) * 3);
		(*returnColumnSizes)[i] = 3;
	}
	return res;
}