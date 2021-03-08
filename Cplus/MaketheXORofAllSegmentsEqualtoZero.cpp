#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minChanges(vector<int> &nums, int k)
	{
		const int INF = 1e9;
		int N = nums.size();
		vector<unordered_map<int, int>> groups(k); //{{val,count}}
		vector<int> count(k);
		for (int i = 0; i < k; ++i)
		{
			for (int j = i; j < N; j += k)
			{
				++groups[i][nums[j]];
				++count[i];
			}
		}
		vector<vector<int>> dp(k + 1, vector<int>(1 << 10, INF));
		dp[0][0] = 0;
		for (int i = 0; i < k; ++i)
		{
			int preMin = *min_element(dp[i].begin(), dp[i].end());
			for (int j = 0; j < 1 << 10; ++j)
			{
				dp[i + 1][j] = min(dp[i + 1][j], preMin + count[i]);
				if (dp[i][j] == INF)
					continue;
				for (auto [n, freq] : groups[i])
				{
					int next = n ^ j;
					dp[i + 1][next] = min(dp[i + 1][next], dp[i][j] + count[i] - freq);
				}
			}
		}
		return dp[k][0];
	}
};