#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int removeBoxes(int *boxes, int boxesSize)
{
	int dp[boxesSize][boxesSize][boxesSize];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < boxesSize; ++i)
	{
		for (int k = 0; k <= i; ++k)
			dp[i][i][k] = (k + 1) * (k + 1);
	}
	for (int i = boxesSize - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < boxesSize; ++j)
		{
			for (int k = 0; k <= i; ++k)
			{
				int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
				for (int m = i + 1; m <= j; ++m)
				{
					if (boxes[m] == boxes[i])
						res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
				}
				dp[i][j][k] = res;
			}
		}
	}
	return dp[0][boxesSize - 1][0];
}