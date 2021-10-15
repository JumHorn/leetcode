
int findNumberOfLIS(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int dp[numsSize][2]; //{LIS,count}
	for (int i = 0; i < numsSize; ++i)
	{
		dp[i][0] = dp[i][1] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (nums[i] > nums[j])
			{
				if (dp[i][0] < dp[j][0] + 1)
				{
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = dp[j][1];
				}
				else if (dp[i][0] == dp[j][0] + 1)
					dp[i][1] += dp[j][1];
			}
		}
	}
	int res = 0, maxlen = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (dp[i][0] > maxlen)
		{
			maxlen = dp[i][0];
			res = dp[i][1];
		}
		else if (dp[i][0] == maxlen)
			res += dp[i][1];
	}
	return res;
}