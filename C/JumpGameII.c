
#define min(a, b) (((a) < (b)) ? (a) : (b))

int jump(int* nums, int numsSize)
{
	if (numsSize == 1)
		return 0;
	int dp[numsSize];
	for (int i = 1; i < numsSize; i++)
		dp[i] = numsSize + 1;
	dp[0] = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] + i >= numsSize - 1)
			return dp[i] + 1;
		for (int j = i + 1; j <= nums[i] + i; j++)
			dp[j] = min(dp[j], dp[i] + 1);
	}
	return -1;
}
