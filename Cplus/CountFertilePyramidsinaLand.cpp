#include <vector>
using namespace std;

class Solution
{
public:
	int countPyramids(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (grid[i][j] != 0)
					grid[i][j] += grid[i][j - 1];
			}
		}
		int res = countPyramid(grid);
		for (int i = 0, j = M - 1; i < j; ++i, --j)
			grid[i].swap(grid[j]);
		res += countPyramid(grid);
		return res;
	}

	int countPyramid(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				int len = 1;
				if (grid[i][j] >= len)
				{
					len += 2;
					for (int d = 1; i + d < M && j + d < N; ++d, len += 2)
					{
						if (grid[i + d][j + d] < len)
							break;
						++res;
					}
				}
			}
		}
		return res;
	}
};