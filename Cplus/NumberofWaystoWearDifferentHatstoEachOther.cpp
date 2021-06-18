#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberWays(vector<vector<int>> &hats)
	{
		int N = hats.size(), hatsType = 40, allmask = (1 << N) - 1;
		vector<vector<int>> h2p(hatsType); //hats to people
		for (int i = 0; i < N; ++i)
		{
			for (auto h : hats[i])
				h2p[h].push_back(i);
		}
		vector<int> dp(1 << N);
		dp[0] = 1;
		for (int bit = 1; bit <= hatsType; ++bit)
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