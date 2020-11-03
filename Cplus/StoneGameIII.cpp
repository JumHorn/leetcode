#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string stoneGameIII(vector<int> &stoneValue)
	{
		int n = stoneValue.size();
		vector<int> prefixsum(n + 1), dp(n + 1, -1);
		dp[n] = 0;
		for (int i = 0; i < n; ++i)
			prefixsum[i + 1] += prefixsum[i] + stoneValue[i];
		int alice = memdp(stoneValue, 0, prefixsum, dp);
		if (alice > prefixsum.back() - alice)
			return "Alice";
		if (alice == prefixsum.back() - alice)
			return "Tie";
		return "Bob";
	}

	int memdp(vector<int> &stone, int index, vector<int> &prefixsum, vector<int> &dp)
	{
		int res = INT_MIN, tmp = 0, n = stone.size();
		if (dp[index] != -1)
			return dp[index];
		n = min(n, index + 3);
		for (int i = index; i < n; ++i)
		{
			tmp += stone[i];
			res = max(res, tmp + prefixsum.back() - prefixsum[i + 1] - memdp(stone, i + 1, prefixsum, dp));
		}
		dp[index] = res;
		return res;
	}
};