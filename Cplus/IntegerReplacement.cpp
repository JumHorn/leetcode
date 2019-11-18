#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int integerReplacement(int n)
	{
		unordered_map<int, int> dp;
		dp[0] = 1;
		dp[1] = 0;
		return recursive(n, dp);
	}

	int recursive(long n, unordered_map<int, int>& dp)
	{
		if (dp.find(n) != dp.end())
			return dp[n];
		int res = 0;
		if (n % 2 == 0)
			res = 1 + recursive(n / 2, dp);
		else
			res = 2 + min(recursive((n - 1) / 2, dp), recursive((n + 1) / 2, dp));
		dp[n] = res;
		return res;
	}
};
