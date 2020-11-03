#include <vector>
using namespace std;

/*
dp[i]
this is one of dp[i]'s state
P...D
dp[i+1] add two new position into the state
P...D##
choose 2 position from 2i positions
Combination(2i,2)
*/

class Solution
{
public:
	int countOrders(int n)
	{
		if (n == 1)
			return 1;
		vector<long> dp(n + 1);
		dp[1] = 1;
		dp[2] = 6;
		for (int i = 3; i <= n; ++i)
			dp[i] = (dp[i - 1] * i * (2 * i - 1)) % MOD;
		return dp[n];
	}

private:
	static const int MOD = 1e9 + 7;
};