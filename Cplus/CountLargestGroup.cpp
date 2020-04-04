class Solution
{
public:
	int countLargestGroup(int n)
	{
		int dp[40] = {0};
		for (int i = 1; i <= n; i++)
		{
			int tmp = i, sum = 0;
			while (tmp != 0)
			{
				sum += tmp % 10;
				tmp /= 10;
			}
			++dp[sum];
		}
		int size = 0, res = 0;
		for (int i = 0; i < 40; i++)
		{
			if (dp[i] > size)
			{
				res = 1;
				size = dp[i];
			}
			else if (dp[i] == size)
				++res;
		}
		return res;
	}
};
