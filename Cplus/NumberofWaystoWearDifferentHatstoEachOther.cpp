#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberWays(vector<vector<int>> &hats)
	{
		int n = hats.size(), N = 41, allmask = (1 << n) - 1;
		vector<vector<int>> h2p(N); //hats to people
		for (int i = 0; i < n; ++i)
		{
			for (auto h : hats[i])
				h2p[h].push_back(i);
		}
		vector<int> dp(1 << n);
		dp[0] = 1;
		for (int bit = 1; bit < N; ++bit)
		{
			for (int mask = allmask; mask >= 0; --mask)
			{
				for (auto p : h2p[bit])
				{
					if (((1 << p) & mask) == 0)
						dp[mask | (1 << p)] = (dp[mask | (1 << p)] + dp[mask]) % MOD;
				}
			}
		}
		return dp[allmask];
	}

private:
	static const int MOD = 1e9 + 7;
};