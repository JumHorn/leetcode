#include <vector>
using namespace std;

class Solution
{
public:
	int maxTurbulenceSize(vector<int>& A)
	{
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = dp[0][1] = 1;
		for (int i = 1; i < n; i++)
		{
			if (A[i] > A[i - 1])
			{
				dp[i][0] = dp[i - 1][1] + 1;
				dp[i][1] = 1;
			}
			else if (A[i] < A[i - 1])
			{
				dp[i][1] = dp[i - 1][0] + 1;
				dp[i][0] = 1;
			}
			else
			{
				dp[i][0] = dp[i][1] = 1;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res = max(res, dp[i][0]);
			res = max(res, dp[i][1]);
		}
		return res;
	}
};
