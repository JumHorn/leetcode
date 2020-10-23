#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubArray(int* nums, int numsSize)
{
	int dp = INT_MIN, res = INT_MIN;
	for (int i = 0; i < numsSize; ++i)
	{
		dp = max(dp, 0) + nums[i];
		res = max(res, dp);
	}
	return res;
}
