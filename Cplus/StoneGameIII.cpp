#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string stoneGameIII(vector<int> &stoneValue)
	{
		int N = stoneValue.size();
		vector<int> prefixsum(N + 1), dp(N + 1, -1);
		dp[N] = 0;
		for (int i = 0; i < N; ++i)
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
		int res = INT_MIN, sum = 0, N = stone.size();
		if (dp[index] != -1)
			return dp[index];
		for (int i = index; i < min(N, index + 3); ++i)
		{
			sum += stone[i];
			res = max(res, sum + prefixsum.back() - prefixsum[i + 1] - memdp(stone, i + 1, prefixsum, dp));
		}
		dp[index] = res;
		return res;
	}
};