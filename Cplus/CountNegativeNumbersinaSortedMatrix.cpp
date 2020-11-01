#include <vector>
using namespace std;

class Solution
{
public:
	int countNegatives(vector<vector<int>> &grid)
	{
		int res = 0, M = grid.size(), N = grid[0].size();
		for (int i = 0, j = N - 1; i < M; ++i)
		{
			while (j >= 0 && grid[i][j] < 0)
				--j;
			res += N - 1 - j;
		}
		return res;
	}
};