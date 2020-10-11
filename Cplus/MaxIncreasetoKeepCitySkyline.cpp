#include <vector>
using namespace std;

class Solution
{
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
	{
		if (grid.empty() || grid[0].empty())
			return 0;
		int M = grid.size(), N = grid[0].size();
		vector<int> h(M), v(N);
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				h[i] = max(grid[i][j], h[i]);
		}
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
				v[j] = max(grid[i][j], v[j]);
		}
		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				res += min(h[i], v[j]) - grid[i][j];
		}
		return res;
	}
};