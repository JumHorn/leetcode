
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minSwap(int* A, int ASize, int* B, int BSize)
{
	int dp[ASize][2];  //{swap,not swap}
	dp[0][0] = 0;
	dp[0][1] = 1;
	for (int i = 1; i < ASize; ++i)
	{
		dp[i][0] = dp[i][1] = ASize;  //max result
		if (A[i] > A[i - 1] && B[i] > B[i - 1])
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		if (A[i] > B[i - 1] && B[i] > A[i - 1])
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);

		if (B[i] > A[i - 1] && A[i] > B[i - 1])
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
		if (B[i] > B[i - 1] && A[i] > A[i - 1])
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
	}
	return min(dp[ASize - 1][0], dp[ASize - 1][1]);
}
