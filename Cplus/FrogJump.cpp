#include <vector>
using namespace std;

class Solution
{
public:
	bool canCross(vector<int> &stones)
	{
		int N = stones.size();
		vector<vector<bool>> dp(N, vector<bool>(N + 1));
		dp[0][1] = true;
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int k = stones[i] - stones[j];
				if (k > N || !dp[j][k])
					continue;
				dp[i][k] = true;
				if (k > 0)
					dp[i][k - 1] = true;
				if (k < N)
					dp[i][k + 1] = true;
				if (i == N - 1)
					return true;
			}
		}
		return false;
	}
};