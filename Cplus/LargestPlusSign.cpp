#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
	{
		vector<int> hash(N * N);
		for (auto &mine : mines)
			hash[mine[0] * N + mine[1]] = 1;
		vector<vector<int>> dp(N, vector<int>(N));
		for (auto &mine : mines)
			hash[mine[0] * N + mine[1]] = 1;
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			count = 0;
			for (int j = 0; j < N; ++j)
			{
				count = hash[i * N + j] == 1 ? 0 : count + 1;
				dp[i][j] = count;
			}
			count = 0;
			for (int j = N - 1; j >= 0; --j)
			{
				count = hash[i * N + j] == 1 ? 0 : count + 1;
				dp[i][j] = min(dp[i][j], count);
			}
		}

		int res = 0;
		for (int j = 0; j < N; ++j)
		{
			count = 0;
			for (int i = 0; i < N; ++i)
			{
				count = hash[i * N + j] == 1 ? 0 : count + 1;
				dp[i][j] = min(dp[i][j], count);
			}
			count = 0;
			for (int i = N - 1; i >= 0; --i)
			{
				count = hash[i * N + j] == 1 ? 0 : count + 1;
				dp[i][j] = min(dp[i][j], count);
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}
};