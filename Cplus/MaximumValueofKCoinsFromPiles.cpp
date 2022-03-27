#include <vector>
using namespace std;

class Solution
{
public:
	int maxValueOfCoins(vector<vector<int>> &piles, int k)
	{
		int N = piles.size();
		vector<vector<int>> dp(N, vector<int>(k + 1));
		for (int i = 0; i < k; ++i)
		{
			if (i < piles[0].size())
				dp[0][i + 1] = piles[0][i] + dp[0][i];
			else
				dp[0][i + 1] = dp[0][i];
		}
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < k; ++j)
			{
				dp[i][j + 1] = dp[i - 1][j + 1];
				int sum = 0;
				for (int n = 0; n <= j && n < piles[i].size(); ++n)
				{
					sum += piles[i][n];
					dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j - n] + sum);
				}
			}
		}
		return dp[N - 1][k];
	}
};