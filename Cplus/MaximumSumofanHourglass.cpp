#include <vector>
using namespace std;

class Solution
{
public:
	int maxSum(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 1; i < M - 1; ++i)
		{
			for (int j = 1; j < N - 1; ++j)
			{
				int sum = 0;
				for (int di = -1; di <= 1; ++di)
				{
					for (int dj = -1; dj <= 1; ++dj)
						sum += grid[i + di][j + dj];
				}
				res = max(res, sum - grid[i][j - 1] - grid[i][j + 1]);
			}
		}
		return res;
	}
};