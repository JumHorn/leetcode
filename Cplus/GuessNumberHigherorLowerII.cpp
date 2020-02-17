#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMoneyAmount(int n)
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
		for (int i = 0; i <= n; i++)
			dp[i][i] = 0;
		for (int i = 1; i < n; i++)
			dp[i][i + 1] = i;
		for (int i = 1; i < n - 1; i++)
			dp[i][i + 2] = i + 1;
		for (int k = 3; k < n; k++)
		{
			for (int i = 1; i <= n - k; i++)
			{
				int j = i + k;
				for (int n = i + 1; n < j; n++)
				{
					dp[i][j] = min(dp[i][j], max(dp[i][n - 1], dp[n + 1][j]) + n);
				}
			}
		}
		return dp[1][n];
	}
};

int main()
{
	Solution sol;
	sol.getMoneyAmount(6);
	return 0;
}