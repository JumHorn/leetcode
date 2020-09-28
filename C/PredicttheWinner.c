#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool PredictTheWinner(int* nums, int numsSize)
{
	int prefixsum[numsSize + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < numsSize; ++i)
		prefixsum[i + 1] = prefixsum[i] + nums[i];
	int sum = prefixsum[numsSize];
	int dp[numsSize][numsSize];
	for (int i = 0; i < numsSize; ++i)
		dp[i][i] = nums[i];
	for (int l = 1; l < numsSize; ++l)
	{
		for (int i = 0, j = l; j < numsSize; ++i, ++j)
			dp[i][j] = max(nums[i] + prefixsum[j + 1] - prefixsum[i + 1] - dp[i + 1][j], nums[j] + prefixsum[j] - prefixsum[i] - dp[i][j - 1]);
	}
	return dp[0][numsSize - 1] * 2 >= sum;
}
