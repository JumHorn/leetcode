#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int largestIsland(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		int res = 0, color = 2;
		vector<int> colorArr(2); //2 reserved for 0 and 1
		//color the grid
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (grid[i][j] == 1)
				{
					colorArr.push_back(colorNode(grid, i, j, color));
					res = max(res, colorArr.back());
					++color;
				}
			}
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (grid[i][j] != 0)
					continue;
				unordered_set<int> colorset;
				int n = 0, area = 0;
				//board dfs direction
				int path[5] = {-1, 0, 1, 0, -1};
				for (int k = 0; k < 4; k++)
				{
					int dx = i + path[k], dy = j + path[k + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N || grid[dx][dy] <= 1)
						continue;
					int c = grid[dx][dy];
					if (colorset.find(c) == colorset.end()) //this color not count yet
					{
						area += colorArr[c];
						colorset.insert(c);
					}
				}
				res = max(res, area + 1); //1 for self
			}
		}
		return res;
	}

	int colorNode(vector<vector<int>> &grid, int row, int col, int color)
	{
		int M = grid.size(), N = grid[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] != 1)
			return 0;
		int res = 1;
		grid[row][col] = color;
		res += colorNode(grid, row - 1, col, color);
		res += colorNode(grid, row + 1, col, color);
		res += colorNode(grid, row, col - 1, color);
		res += colorNode(grid, row, col + 1, color);
		return res;
	}
};