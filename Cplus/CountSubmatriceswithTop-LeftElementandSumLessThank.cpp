#include <vector>
using namespace std;

class Solution
{
public:
	int countSubmatrices(vector<vector<int>> &grid, int k)
	{
		int M = grid.size(), N = grid[0].size(), res = 0;
		for (int i = 0; i < M; ++i)
		{
			long long prefixsum = grid[i][0];
			for (int j = 0; j < N; ++j)
			{
				if (j > 0)
				{
					if (prefixsum > k)
					{
						grid[i][j] = k + 1;
						break;
					}
					prefixsum += grid[i][j];
				}
				if (i > 0)
				{
					if (grid[i - 1][j] > k)
					{
						grid[i][j] = k + 1;
						break;
					}
					grid[i][j] = grid[i - 1][j] + prefixsum;
				}
				else
					grid[i][j] = prefixsum;
				if (grid[i][j] > k)
					break;
				++res;
			}
		}
		return res;
	}
};