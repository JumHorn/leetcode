#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int largest1BorderedSquare(vector<vector<int>> &grid)
	{
		int dp[102][102][4] = {{{0}}};
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) //up
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					dp[i + 1][j + 1][0] = dp[i][j + 1][0] + 1;
			}
		}
		for (int i = m - 1; i >= 0; i--) //down
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					dp[i + 1][j + 1][1] = dp[i + 2][j + 1][1] + 1;
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++) //left
			{
				if (grid[i][j] == 1)
					dp[i + 1][j + 1][2] = dp[i + 1][j][2] + 1;
			}
		}
		for (int j = n - 1; j >= 0; j--)
		{
			for (int i = 0; i < m; i++) //right
			{
				if (grid[i][j] == 1)
					dp[i + 1][j + 1][3] = dp[i + 1][j + 2][3] + 1;
			}
		}

		int res = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (grid[i - 1][j - 1] == 1)
				{
					int size = min(dp[i][j][1], dp[i][j][3]);
					for (int k = res; k < size; k++)
					{
						if (dp[i + k][j + k][0] >= k && dp[i + k][j + k][2] >= k)
							res = k + 1;
					}
				}
			}
		return res * res;
	}
};