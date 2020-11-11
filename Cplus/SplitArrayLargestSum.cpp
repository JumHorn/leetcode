#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int splitArray(vector<int> &nums, int m)
	{
		int N = nums.size();
		vector<long> prefix(N + 1);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] += prefix[i] + nums[i];
		vector<vector<long>> dp(N + 1, vector<long>(m + 1));
		for (int i = 0; i < N; ++i)
			dp[i + 1][1] = prefix[i + 1];
		for (int j = 2; j <= m; ++j)
		{
			for (int i = j - 1; i <= N; ++i)
			{
				dp[i][j] = INT_MAX;
				for (int k = i - 1; k >= j - 2; --k)
					dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix[i] - prefix[k]));
			}
		}
		return dp[N][m];
	}
};