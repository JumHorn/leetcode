#include <string.h>

/*
dp[i][j] the max coins not include burst boundary i and j
dp[i][j] = max{nums[i]*nums[k]*nums[j]+dp[i][k]+dp[k][j]} (i<k<j)
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxCoins(int *nums, int numsSize)
{
	int N = numsSize + 2;
	int dp[N][N], dup[N];
	memcpy(&dup[1], nums, sizeof(int) * numsSize);
	dup[0] = dup[N - 1] = 1;
	memset(dp, 0, sizeof(dp));
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = max(dp[i][j], dup[i] * dup[k] * dup[j] + dp[i][k] + dp[k][j]);
		}
	}
	return dp[0][N - 1];
}