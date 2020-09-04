#include <stdbool.h>

bool winnerSquareGame(int n)
{
	static bool dp[100001];
	dp[0] = false;
	dp[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j * j <= i; ++j)
		{
			if (dp[i - j * j] == false)
			{
				dp[i] = true;
				break;
			}
		}
	}
	return dp[n];
}
