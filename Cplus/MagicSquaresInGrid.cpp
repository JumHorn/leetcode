#include <vector>
using namespace std;

class Solution
{
public:
	int numMagicSquaresInside(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 1; i < M - 1; ++i)
		{
			for (int j = 1; j < N - 1; ++j)
			{
				if (grid[i][j] == 5 &&
					grid[i - 1][j - 1] != 5 &&
					grid[i - 1][j + 1] != 5 &&
					grid[i + 1][j - 1] != 5 &&
					grid[i + 1][j + 1] != 5 &&
					grid[i - 1][j - 1] &&
					grid[i - 1][j] &&
					grid[i - 1][j + 1] &&
					grid[i][j - 1] &&
					grid[i][j + 1] &&
					grid[i + 1][j - 1] &&
					grid[i + 1][j] &&
					grid[i + 1][j + 1])
				{
					if (grid[i - 1][j] + grid[i + 1][j] == 10 &&
						grid[i][j - 1] + grid[i][j + 1] == 10 &&
						grid[i - 1][j - 1] + grid[i + 1][j + 1] == 10 &&
						grid[i - 1][j + 1] + grid[i + 1][j - 1] == 10 &&
						grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] == 15 &&
						grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 15 &&
						grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] == 15 &&
						grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] == 15)
						++res;
				}
			}
		}
		return res;
	}
};