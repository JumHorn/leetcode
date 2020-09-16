#include <vector>
using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		if (n < 3)
			return n;
		vector<int> dp(n + 1);
		dp[0] = dp[1] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
				dp[i + 1] += dp[j] * dp[i - j];
		}
		return dp[n];
	}
};