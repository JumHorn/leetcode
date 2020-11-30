#include <unordered_map>
using namespace std;

class Solution
{
public:
	int memdp(int n, unordered_map<int, int> &dp)
	{
		if (n == 0)
			return 0;
		if (dp.find(n) != dp.end())
			return dp[n];
		int res = 1 + n % 2 + memdp(n / 2, dp);
		res = min(res, 1 + n % 3 + memdp(n / 3, dp));
		return dp[n] = res;
	}

	int minDays(int n)
	{
		unordered_map<int, int> dp;
		return memdp(n, dp) - 1;
	}
};