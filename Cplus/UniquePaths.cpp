#include <vector>
using namespace std;

/*
dynamic programming
dp(m,n)=dp(m-1,n)+dp(m,n-1)
dp(1,n)=1
dp(m,1)=1
*/

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
				dp[j] += dp[j - 1];
		}
		return dp[n - 1];
	}
};