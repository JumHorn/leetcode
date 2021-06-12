#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestMagicSquare(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		int side = min(M, N);
		for (int l = side; l > 1; --l)
		{
			for (int i = 0; i <= M - l; ++i)
			{
				for (int j = 0; j <= N - l; ++j)
				{
					if (checkSquare(grid, i, j, l))
						return l;
				}
			}
		}
		return 1;
	}

	bool checkSquare(vector<vector<int>> &grid, int row, int col, int side)
	{
		int sum = 0;
		for (int i = 0; i < side; ++i)
			sum += grid[row][col + i];

		for (int i = 1; i < side; ++i)
		{
			int tmp = 0;
			for (int j = 0; j < side; ++j)
				tmp += grid[row + i][col + j];
			if (tmp != sum)
				return false;
		}

		for (int j = 0; j < side; ++j)
		{
			int tmp = 0;
			for (int i = 0; i < side; ++i)
				tmp += grid[row + i][col + j];
			if (tmp != sum)
				return false;
		}

		int tmp = 0;
		for (int i = 0; i < side; ++i)
			tmp += grid[row + i][col + i];
		if (tmp != sum)
			return false;

		tmp = 0;
		for (int i = 0; i < side; ++i)
			tmp += grid[row + i][col + side - i - 1];
		if (tmp != sum)
			return false;
		return true;
	}
};