#include <vector>
using namespace std;

class Solution
{
public:
	int cherryPickup(vector<vector<int>>& grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
		return memdp(grid, 0, 0, n - 1, dp);
	}

	int memdp(vector<vector<int>>& grid, int row, int bot1, int bot2, vector<vector<vector<int>>>& dp)
	{
		int n = grid[0].size();
		if (row >= (int)grid.size())
			return 0;
		if (dp[row][bot1][bot2] != -1)
			return dp[row][bot1][bot2];
		int collect = 0;
		if (bot1 == bot2)
			collect = grid[row][bot1];
		else
			collect = grid[row][bot1] + grid[row][bot2];
		int res = 0;
		for (int i = max(bot1 - 1, 0); i <= min(bot1 + 1, n - 1); i++)
		{
			for (int j = max(bot2 - 1, 0); j <= min(bot2 + 1, n - 1); j++)
			{
				res = max(res, memdp(grid, row + 1, i, j, dp));
			}
		}
		res += collect;
		return dp[row][bot1][bot2] = res;
	}
};
