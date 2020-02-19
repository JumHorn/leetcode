

int clumsy(int N)
{
	int arr[] = {1, 2, 6, 7, 7, 8};
	if (N <= 6)
	{
		return arr[N - 1];
	}
	int dp[] = {0, 1, 1, 1, -2, 0, 1};
	int k = N / 7;
	int res = (N + 1 + (N + 8 - 7 * k)) * k / 2 + dp[N % 7];
	if (N == 7)
		res -= 2;
	else if (N == 8)
		res -= 1;
	return res;
}

