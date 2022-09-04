#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfWays(int startPos, int endPos, int k)
	{
		const int offset = 1000;
		vector<int> dp(max(startPos, endPos) + k + offset + 5);
		int N = dp.size();
		dp[startPos + offset] = 1;
		for (int i = 0; i < k; ++i)
		{
			vector<int> dp_copy(N);
			dp.swap(dp_copy);
			for (int j = 1; j < N - 1; ++j)
			{
				dp[j - 1] = (dp[j - 1] + dp_copy[j]) % MOD;
				dp[j + 1] = (dp[j + 1] + dp_copy[j]) % MOD;
			}
		}
		return dp[endPos + offset];
	}

private:
	static const int MOD = 1e9 + 7;
};