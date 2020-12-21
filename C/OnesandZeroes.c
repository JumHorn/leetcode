#include <string.h>

//knapsack

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findMaxForm(char **strs, int strsSize, int m, int n)
{
	int arr[strsSize][2];
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < strsSize; ++i)
	{
		for (int j = 0; strs[i][j]; ++j)
			++arr[i][strs[i][j] - '0'];
	}
	int dp[strsSize + 1][m + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < strsSize; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				if (j >= arr[i][0] && k >= arr[i][1])
					dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - arr[i][0]][k - arr[i][1]] + 1);
				else
					dp[i + 1][j][k] = dp[i][j][k];
			}
		}
	}
	return dp[strsSize][m][n];
}