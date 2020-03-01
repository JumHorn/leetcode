#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<vector<int>> &grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, -1));
		return memdp(grid, dp, 0, 0);
	}

	int memdp(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j)
	{
		int m = grid.size(), n = grid[0].size();
		if (i < 0 || i >= m || j < 0 || j >= n)
			return 100000;
		if (dp[i][j] != -1)
			return dp[i][j];
		if (i == m - 1 && j == n - 1)
			return 0;
		int res = INT_MAX;
		if (grid[i][j] == 0)
			return 100000;
		int sign = grid[i][j];
		grid[i][j] = 0;
		res = min(res, memdp(grid, dp, i - 1, j) + (sign == 4 ? 0 : 1));
		res = min(res, memdp(grid, dp, i + 1, j) + (sign == 3 ? 0 : 1));
		res = min(res, memdp(grid, dp, i, j - 1) + (sign == 2 ? 0 : 1));
		res = min(res, memdp(grid, dp, i, j + 1) + (sign == 1 ? 0 : 1));
		grid[i][j] = sign;
		dp[i][j] = res;
		return res;
	}
};
