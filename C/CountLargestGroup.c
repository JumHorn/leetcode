
int sumDigits(int n)
{
	int res = 0;
	for (; n != 0; n /= 10)
		res += n % 10;
	return res;
}

int countLargestGroup(int n)
{
	int dp[40] = {0};
	for (int i = 1; i <= n; ++i)
		++dp[sumDigits(i)];
	int size = 0, res = 0;
	for (int i = 0; i < 40; ++i)
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
