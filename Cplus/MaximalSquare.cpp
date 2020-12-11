#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximalSquare(vector<vector<char>> &matrix)
	{
		if (matrix.empty())
			return 0;
		int res = 0, M = matrix.size(), N = matrix[0].size();
		vector<int> dp(N + 1);
		for (int i = 0; i < M; ++i)
		{
			vector<int> dp_next(N + 1);
			for (int j = 0; j < N; ++j)
			{
				if (matrix[i][j] == '1')
				{
					dp_next[j + 1] = min({dp[j + 1], dp[j], dp_next[j]}) + 1;
					res = max(res, dp_next[j + 1]);
				}
			}
			dp.swap(dp_next);
		}
		return res * res;
	}
};