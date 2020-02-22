#include <vector>
using namespace std;

class Solution
{
public:
	int countOrders(int n)
	{
		if (n == 1)
			return 1;
		static const int MOD = 1e9 + 7;
		vector<long> dp(n + 1);
		dp[1] = 1;
		dp[2] = 6;
		for (int i = 3; i <= n; i++)
			dp[i] = (dp[i - 1] * i * (2 * i - 1)) % MOD;
		return dp[n];
	}
};