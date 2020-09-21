
#define max(a, b) (((a) > (b)) ? (a) : (b))

int doRob(int* nums, int numsSize)
{
	int dp[numsSize + 1];
	dp[0] = 0;
	dp[1] = nums[0];
	for (int i = 1; i < numsSize; ++i)
		dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
	return dp[numsSize];
}

int rob(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int r0 = doRob(nums, numsSize - 1);
	int r1 = doRob(nums + 1, numsSize - 1);
	return max(r0, r1);
}
