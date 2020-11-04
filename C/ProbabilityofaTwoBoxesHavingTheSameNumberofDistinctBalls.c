#include <string.h>

/*
dp[m][k] saves number of cases with equal number of colors in both boxes and k balls in the first box
and dp[m-x][k] saves number of cases where first box has x less colors, and dp[m+x][k] saves number of cases where first box has x more colors
*/

double getProbability(int *balls, int ballsSize)
{
	int m = ballsSize;
	int S = 0;
	for (int i = 0; i < m; ++i)
		S += balls[i];

	//combination table
	double C[S + 1][S / 2 + 1];
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 1; i < S + 1; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < S / 2 + 1; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	//dp
	double dp[2 * m + 1][S / 2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[m][0] = 1;
	int sum = 0;
	for (int k = 0; k < m; ++k)
	{
		int b = balls[k];
		sum += b;
		double ndp[2 * m + 1][S / 2 + 1];
		memset(ndp, 0, sizeof(ndp));
		for (int i = 0; i <= b; ++i)
		{
			for (int j = 0; j < 2 * m + 1; ++j)
			{
				for (int k = 0; k < S / 2 + 1; k++)
				{
					if (dp[j][k] == 0)
						continue;
					int nk = k + i;
					int nr = sum - nk;
					if (nk <= S / 2 && nr <= S / 2)
					{
						int nj = (i == 0) ? j - 1 : (i == b) ? j + 1 : j;
						ndp[nj][nk] += dp[j][k] * C[b][i];
					}
				}
			}
		}
		memcpy(dp, ndp, sizeof(dp));
	}
	return dp[m][S / 2] / C[S][S / 2];
}