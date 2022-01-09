#include <vector>
using namespace std;

class Solution
{
public:
	bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> count(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				count[i + 1][j + 1] = count[i][j + 1] + count[i + 1][j] - count[i][j] + grid[i][j];
		}
		vector<vector<int>> stamps(M, vector<int>(N));
		for (int i = 0; i <= M - stampHeight; ++i)
		{
			for (int j = 0; j <= N - stampWidth; ++j)
			{
				if (!exists(count, i, j, i + stampHeight, j + stampWidth))
					stamps[i][j] = 1;
			}
		}
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + stamps[i][j];
		}

		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0 && !exists(dp, i + 1 - stampHeight, j + 1 - stampWidth, i + 1, j + 1))
					return false;
			}
		}
		return true;
	}

	bool exists(vector<vector<int>> &matrix, int startx, int starty, int endx, int endy)
	{
		int M = matrix.size(), N = matrix[0].size();
		int x = max(startx, 0), y = max(starty, 0);
		int r = min(M, endx), c = min(N, endy);
		return matrix[r][c] - matrix[x][c] - matrix[r][y] + matrix[x][y] > 0;
	}
};