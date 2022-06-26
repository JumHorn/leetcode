#include <vector>
using namespace std;

class Solution
{
public:
	bool checkXMatrix(vector<vector<int>> &grid)
	{
		int N = grid.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (j == i)
				{
					if (grid[i][i] == 0)
						return false;
				}
				else if (j == N - 1 - i)
				{
					if (grid[i][N - 1 - i] == 0)
						return false;
				}
				else if (grid[i][j] != 0)
					return false;
			}
		}
		return true;
	}
};