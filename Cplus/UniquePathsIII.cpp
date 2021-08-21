#include <vector>
using namespace std;

class Solution
{
public:
	int uniquePathsIII(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), mask = 0, startx = 0, starty = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
				{
					startx = i;
					starty = j;
				}
				else if (grid[i][j] == 0 || grid[i][j] == 2)
					mask |= encode(i, j, N);
			}
		}
		vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(1 << M * N, -1)));
		return memdp(grid, startx, starty, mask, dp); //for the start pos will consume count from allzero
	}

	int memdp(vector<vector<int>> &grid, int r, int c, int mask, vector<vector<vector<int>>> &dp)
	{
		int M = grid.size(), N = grid[0].size();
		if (grid[r][c] == 2)
			return mask == 0 ? 1 : 0;
		if (dp[r][c][mask] != -1)
			return dp[r][c][mask];
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		int res = 0;
		for (int i = 0; i < 4; ++i)
		{
			int dx = r + path[i], dy = c + path[i + 1];
			if (dx >= M || dx < 0 || dy >= N || dy < 0)
				continue;
			if ((mask & encode(dx, dy, N)) != 0)
				res += memdp(grid, dx, dy, mask ^ encode(dx, dy, N), dp);
		}
		return dp[r][c][mask] = res;
	}

	int encode(int r, int c, int N)
	{
		return 1 << (r * N + c);
	}
};