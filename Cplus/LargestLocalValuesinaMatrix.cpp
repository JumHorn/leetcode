#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> largestLocal(vector<vector<int>> &grid)
	{
		int N = grid.size();
		vector<vector<int>> res(N - 2, vector<int>(N - 2));
		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = 0; j < N - 2; ++j)
			{
				for (int di = -1; di <= 1; ++di)
				{
					for (int dj = -1; dj <= 1; ++dj)
						res[i][j] = max(res[i][j], grid[i + 1 + di][j + 1 + dj]);
				}
			}
		}
		return res;
	}
};