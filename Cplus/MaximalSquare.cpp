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
			vector<int> dp1(N + 1);
			for (int j = 0; j < N; ++j)
			{
				if (matrix[i][j] == '1')
				{
					dp1[j + 1] = min({dp[j + 1], dp[j], dp1[j]}) + 1;
					res = max(res, dp1[j + 1]);
				}
			}
			dp.swap(dp1);
		}
		return res * res;
	}
};