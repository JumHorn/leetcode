#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberWays(vector<vector<int>> &hats)
	{
		int n = hats.size();
		vector<vector<int>> dp(41, vector<int>(1 << n, -1));
		vector<vector<int>> h2p(41); //hats to people
		for (int i = 0; i < n; i++)
			for (auto h : hats[i])
				h2p[h].push_back(i);
		return memdp(h2p, 1, 0, (1 << n) - 1, dp);
	}

	int memdp(vector<vector<int>> &h2p, int index, int mask, int allmask, vector<vector<int>> &dp)
	{
		if (mask == allmask)
			return 1;
		if (index > 40)
			return 0;
		if (dp[index][mask] != -1)
			return dp[index][mask];
		int res = memdp(h2p, index + 1, mask, allmask, dp);
		for (auto p : h2p[index])
		{
			if ((mask & (1 << p)) == 0)
				res = (res + memdp(h2p, index + 1, mask | (1 << p), allmask, dp)) % MOD;
		}
		return dp[index][mask] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};