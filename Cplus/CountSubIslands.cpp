#include <vector>
using namespace std;

class Solution
{
public:
	int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
	{
		int M = grid1.size(), N = grid1[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid2[i][j] == 1)
				{
					if (dfs(grid1, grid2, i, j))
						++res;
				}
			}
		}
		return res;
	}

	bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int row, int col)
	{
		int M = grid1.size(), N = grid1[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || grid2[row][col] == 0)
			return true;
		grid2[row][col] = 0;
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		bool res = (grid1[row][col] != 0);
		for (int i = 0; i < 4; ++i)
			res = (dfs(grid1, grid2, row + path[i], col + path[i + 1]) && res);
		return res;
	}
};