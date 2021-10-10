#include <stdbool.h>

/*
TSP DP problem
*/

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
	int M = maxChoosableInteger, T = desiredTotal;
	if (T <= 1)
		return true;
	if (M * (M + 1) / 2 < T)
		return false;
	if (M * (M + 1) / 2 == T) //who choose last one wins
		return M & 1;
	int dp[1 << M]; // 0 -- invalid; 1 -- lose; 2 -- win
	//mask 1 bit already choosed, 0 bit not choosed yet
	for (int mask = (1 << M) - 1; mask >= 0; --mask)
	{
		int choosed = 0;
		for (int bit = 0; bit < M; ++bit)
		{
			if (((1 << bit) & mask) != 0)
				choosed += bit + 1;
		}
		if (choosed >= desiredTotal) //already game over
		{
			dp[mask] = 0; //invalid state
			continue;
		}
		dp[mask] = 1;
		for (int bit = 0; bit < M; ++bit)
		{
			if (((1 << bit) & mask) == 0)
			{
				int pre = (mask ^ (1 << bit));
				if (choosed + bit + 1 >= desiredTotal || dp[pre] == 1)
				{
					dp[mask] = 2;
					break;
				}
			}
		}
	}
	return dp[0] == 2;
}