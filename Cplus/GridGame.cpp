#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long gridGame(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<long long>> prefix(M, vector<long long>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				prefix[i][j + 1] = prefix[i][j] + grid[i][j];
		}

		long long res = prefix[0].back() + prefix[1].back();
		for (int i = 0; i < N; ++i)
			res = min(res, max(prefix[0].back() - prefix[0][i + 1], prefix[1][i]));
		return res;
	}
};