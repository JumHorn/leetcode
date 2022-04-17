#include <vector>
using namespace std;

class Solution
{
public:
	int maxTrailingZeros(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<pair<int, int>>> dp0(M, vector<pair<int, int>>(N + 1)), dp1(M + 1, vector<pair<int, int>>(N)); //{2's count,5's count}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				auto [t, f] = twoAndFive(grid[i][j]);
				dp0[i][j + 1].first = dp0[i][j].first + t;
				dp0[i][j + 1].second = dp0[i][j].second + f;
			}
		}

		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
			{
				auto [t, f] = twoAndFive(grid[i][j]);
				dp1[i + 1][j].first = dp1[i][j].first + t;
				dp1[i + 1][j].second = dp1[i][j].second + f;
			}
		}

		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				res = max(res, min(dp0[i][j + 1].first + dp1[i][j].first, dp0[i][j + 1].second + dp1[i][j].second));
				res = max(res, min(dp0[i][j + 1].first + (dp1[M][j].first - dp1[i + 1][j].first),
								   dp0[i][j + 1].second + (dp1[M][j].second - dp1[i + 1][j].second)));
				res = max(res, min(dp0[i][N].first - dp0[i][j].first + dp1[i][j].first, dp0[i][N].second - dp0[i][j].second + dp1[i][j].second));
				res = max(res, min(dp0[i][N].first - dp0[i][j].first + (dp1[M][j].first - dp1[i + 1][j].first),
								   dp0[i][N].second - dp0[i][j].second + (dp1[M][j].second - dp1[i + 1][j].second)));

				res = max(res, min(dp1[i + 1][j].first + dp0[i][j].first, dp1[i + 1][j].second + dp0[i][j].second));
				res = max(res, min(dp1[i + 1][j].first + (dp0[i][N].first - dp0[i][j + 1].first),
								   dp1[i + 1][j].second + (dp0[i][N].second - dp0[i][j + 1].second)));
				res = max(res, min(dp1[M][j].first - dp1[i][j].first + dp0[i][j].first, dp1[M][j].second - dp1[i][j].second + dp0[i][j].second));
				res = max(res, min(dp1[M][j].first - dp1[i][j].first + (dp0[i][N].first - dp0[i][j + 1].first),
								   dp1[M][j].second - dp1[i][j].second + (dp0[i][N].second - dp0[i][j + 1].second)));
			}
		}
		return res;
	}

	pair<int, int> twoAndFive(int n)
	{
		int two = 0;
		for (int t = n; t % 2 == 0; t /= 2)
			++two;
		int five = 0;
		for (int f = n; f % 5 == 0; f /= 5)
			++five;
		return {two, five};
	}
};