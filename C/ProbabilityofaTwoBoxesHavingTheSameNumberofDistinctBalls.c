#include <string.h>

/*
dp[N][k] saves number of cases with equal number of colors in both boxes and k balls in the first box
and dp[N-x][k] saves number of cases where first box has x less colors, and dp[N+x][k] saves number of cases where first box has x more colors
*/

double getProbability(int *balls, int ballsSize)
{
	int N = ballsSize;
	int S = 0;
	for (int i = 0; i < N; ++i)
		S += balls[i];

	//combination table
	double combination[S + 1][S / 2 + 1];
	memset(combination, 0, sizeof(combination));
	combination[0][0] = 1;
	for (int i = 1; i < S + 1; ++i)
	{
		combination[i][0] = 1;
		for (int j = 1; j < S / 2 + 1; ++j)
			combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
	}

	//dp
	double dp[2 * N + 1][S / 2 + 1];
	memset(dp, 0, sizeof(dp));
	dp[N][0] = 1; //dp begins from this point
	int sum = 0;
	for (int n = 0; n < N; ++n) //different color balls
	{
		int b = balls[n];
		sum += b;
		double next_dp[2 * N + 1][S / 2 + 1];
		memset(next_dp, 0, sizeof(next_dp));
		for (int i = 0; i <= b; ++i) //distribute balls to each box
		{
			for (int j = 0; j < 2 * N + 1; ++j) //color diff
			{
				for (int k = 0; k < S / 2 + 1; ++k) // first box ball count
				{
					if (dp[j][k] == 0)
						continue;
					int ballCount = k + i;
					int other = sum - ballCount;
					if (ballCount <= S / 2 && other <= S / 2)
					{
						int colorDiff = (i == 0) ? j - 1 : (i == b) ? j + 1 : j;
						next_dp[colorDiff][ballCount] += dp[j][k] * combination[b][i];
					}
				}
			}
		}
		memcpy(dp, next_dp, sizeof(dp));
	}
	return dp[N][S / 2] / combination[S][S / 2];
}