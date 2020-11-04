#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int calculateMinimumHP(vector<vector<int>> &dungeon)
	{
		int M = dungeon.size(), N = dungeon[0].size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M - 1; ++i)
			dp[i][N] = INT_MAX;
		for (int i = 0; i < N - 1; ++i)
			dp[M][i] = INT_MAX;
		dp[M - 1][N] = dp[M][N - 1] = 1;
		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				int hp = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
				dp[i][j] = hp <= 0 ? 1 : hp;
			}
		}
		return dp[0][0];
	}
};