
#define max(a, b) (((a) > (b)) ? (a) : (b))

int deleteAndEarn(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int dp[10001] = {0}, size = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		size = max(size, nums[i]);
		dp[nums[i]] += nums[i];
	}
	for (int i = 2; i <= size; ++i)
		dp[i] = max(dp[i - 1], dp[i - 2] + dp[i]);
	return dp[size];
}
