#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallestRange(int **nums, int numsSize, int *numsColSize, int *returnSize)
{
	int index[numsSize], maxindex = 0, minindex = 0;
	*returnSize = 2;
	int *res = (int *)malloc(sizeof(int) * 2);
	memset(index, 0, sizeof(index));
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i][0] < nums[minindex][0])
			minindex = i;
		if (nums[i][0] > nums[maxindex][0])
			maxindex = i;
	}
	int range = nums[maxindex][index[maxindex]] - nums[minindex][index[minindex]];
	res[0] = nums[minindex][index[minindex]];
	res[1] = nums[maxindex][index[maxindex]];

	while (index[minindex] + 1 < numsColSize[minindex])
	{
		++index[minindex];
		if (nums[maxindex][index[maxindex]] < nums[minindex][index[minindex]])
			maxindex = minindex;
		minindex = 0;
		for (int i = 0; i < numsSize; ++i)
		{
			if (nums[i][index[i]] < nums[minindex][index[minindex]])
				minindex = i;
		}
		int tmp = nums[maxindex][index[maxindex]] - nums[minindex][index[minindex]];
		if (tmp < range)
		{
			range = tmp;
			res[0] = nums[minindex][index[minindex]];
			res[1] = nums[maxindex][index[maxindex]];
		}
	}
	return res;
}