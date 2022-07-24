#include <vector>
using namespace std;

class Solution
{
public:
	int equalPairs(vector<vector<int>> &grid)
	{
		int res = 0, N = grid.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (equal(grid, i, j))
					++res;
			}
		}
		return res;
	}

	bool equal(vector<vector<int>> &grid, int r, int c)
	{
		int N = grid.size();
		for (int i = 0; i < N; ++i)
		{
			if (grid[i][c] != grid[r][i])
				return false;
		}
		return true;
	}
};