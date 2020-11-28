#include <vector>
using namespace std;

class Solution
{
public:
	int cherryPickup(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(N, -1)));
		return memdp(grid, 0, 0, N - 1, dp);
	}

	int memdp(vector<vector<int>> &grid, int row, int bot1, int bot2, vector<vector<vector<int>>> &dp)
	{
		int M = grid.size(), N = grid[0].size();
		if (row >= M)
			return 0;
		if (dp[row][bot1][bot2] != -1)
			return dp[row][bot1][bot2];
		int collect = 0;
		if (bot1 == bot2)
			collect = grid[row][bot1];
		else
			collect = grid[row][bot1] + grid[row][bot2];
		int res = 0;
		for (int i = max(bot1 - 1, 0); i <= min(bot1 + 1, N - 1); ++i)
		{
			for (int j = max(bot2 - 1, 0); j <= min(bot2 + 1, N - 1); ++j)
				res = max(res, memdp(grid, row + 1, i, j, dp));
		}
		res += collect;
		return dp[row][bot1][bot2] = res;
	}
};