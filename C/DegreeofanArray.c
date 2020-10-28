#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int findShortestSubArray(int* nums, int numsSize)
{
	int index[50000], count[50000] = {0}, res = numsSize, degree = 0;
	memset(index, -1, sizeof(index));
	for (int i = 0; i < numsSize; ++i)
	{
		if (index[nums[i]] == -1)
			index[nums[i]] = i;
		if (++count[nums[i]] > degree)
		{
			degree = count[nums[i]];
			res = i - index[nums[i]] + 1;
		}
		else if (count[nums[i]] == degree)
			res = min(res, i - index[nums[i]] + 1);
	}
	return res;
}
