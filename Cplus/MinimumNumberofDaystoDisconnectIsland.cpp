#include <vector>
using namespace std;

class Solution
{
public:
	int minDays(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		int land1 = -1, land2 = -1, count = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0)
					continue;
				if (land1 == -1)
					land1 = i * N + j;
				else if (land2 == -1)
					land2 = i * N + j;
				++count;
			}
		}
		if (count == 1)
			return 1;

		vector<vector<int>> seen(M, vector<int>(N));
		if (connectedCount(grid, land1 / N, land1 % N, seen) != count) //already disconnected
			return 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
				{
					vector<vector<int>> seen(M, vector<int>(N));
					grid[i][j] = 0;
					int land = (land1 == i * N + j ? land2 : land1);
					if (connectedCount(grid, land / N, land % N, seen) != count - 1) //already disconnected
						return 1;
					grid[i][j] = 1;
				}
			}
		}
		return 2;
	}

	int connectedCount(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &seen)
	{
		int M = grid.size(), N = grid[0].size();
		seen[row][col] = 1;
		int path[5] = {-1, 0, 1, 0, -1};
		int res = 1;
		for (int i = 0; i < 4; ++i)
		{
			int dx = row + path[i], dy = col + path[i + 1];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N &&
				grid[dx][dy] != 0 && seen[dx][dy] == 0)
				res += connectedCount(grid, dx, dy, seen);
		}
		return res;
	}
};