#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberWays(vector<vector<int>>& hats)
	{
		vector<unordered_map<int, int>> dp(hats.size());
		return memdp(hats, 0, 0, dp);
	}

	int memdp(vector<vector<int>>& hats, long seen, int index, vector<unordered_map<int, int>>& dp)
	{
		int n = hats.size(), res = 0;
		if (index >= n)
			return 1;
		if (dp[index].find(seen) != dp[index].end())
			return dp[index][seen];
		for (auto h : hats[index])
		{
			if ((seen & (1 << h)) == 0)
			{
				seen += (1 << h);
				res = (res + memdp(hats, seen, index + 1, dp)) % MOD;
				seen -= (1 << h);
			}
		}
		dp[index][seen] = res;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
