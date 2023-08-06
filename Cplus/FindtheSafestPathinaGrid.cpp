#include <vector>
using namespace std;

class Solution
{
public:
	int maximumSafenessFactor(vector<vector<int>> &grid)
	{
		int N = grid.size();
		init(grid);
		int lo = 0, hi = min(grid[0][0], grid[N - 1][N - 1]) + 1;
		while (lo < hi)
		{
			vector<vector<int>> grid1 = grid;
			int mi = (hi - lo) / 2 + lo;
			if (canDo(grid1, 0, 0, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool canDo(vector<vector<int>> &grid, int x, int y, int d)
	{
		int path[] = {-1, 0, 1, 0, -1};
		int N = grid.size();
		if (x == N - 1 && y == N - 1)
			return true;
		bool res = false;
		grid[x][y] = -1;
		for (int k = 0; k < 4; ++k)
		{
			int dx = x + path[k], dy = y + path[k + 1];
			if (dx < 0 || dx >= N || dy < 0 || dy >= N || grid[dx][dy] < d)
				continue;
			if (canDo(grid, dx, dy, d))
			{
				res = true;
				break;
			}
		}
		return res;
	}

	void init(vector<vector<int>> &dp)
	{
		int N = dp.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (dp[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = (1 << 10); // init to a large number
			}
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == 0 && j == 0)
					dp[i][j] = dp[i][j];
				else if (i == 0)
					dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
				else if (j == 0)
					dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
				else
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i][j]);
			}
		}

		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (i == N - 1 && j == N - 1)
					dp[i][j] = dp[i][j];
				else if (i == N - 1)
					dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
				else if (j == N - 1)
					dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
				else
					dp[i][j] = min(min(dp[i + 1][j], dp[i][j + 1]) + 1, dp[i][j]);
			}
		}
	}
};