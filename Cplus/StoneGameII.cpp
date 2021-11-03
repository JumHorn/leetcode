#include <vector>
using namespace std;

/*
dp[i][j] is the maximum number of stones Alex can get when starting at index i with M = j
suffixsum[i] is the total number of stones from index i to the end
The dp matrix for Lee is the same.
And the stragegy for Alex is to choose an optimal X to
minimize the number of stones Lee can get when starting at index (i + X) with M = max(X,j).
Here we have the recurrence formula

dp[i][j] = max(suffixsum[i] - dp[i + X][max(j, X)]) where 1<= X <= 2j;
*/

class Solution
{
public:
	int stoneGameII(vector<int> &piles)
	{
		int N = piles.size(), suffixsum = 0;
		vector<vector<int>> dp(N, vector<int>(N + 1));
		for (int i = N - 1; i >= 0; --i)
		{
			suffixsum += piles[i];
			for (int j = 1; j <= N; ++j)
			{
				if (i + 2 * j >= N)
					dp[i][j] = suffixsum;
				else
				{
					for (int X = 1; X <= 2 * j; ++X)
						dp[i][j] = max(dp[i][j], suffixsum - dp[i + X][max(j, X)]);
				}
			}
		}
		return dp[0][1];
	}
};