#include <vector>
using namespace std;

class Solution
{
public:
	int minScoreTriangulation(vector<int>& A)
	{
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n));
		return memdp(dp, A, 0, n - 1);
	}

	int memdp(vector<vector<int>>& dp, vector<int>& A, int i, int j)
	{
		if (i + 1 >= j)
			return 0;
		if (dp[i][j] != 0)
			return dp[i][j];
		int res = INT_MAX;
		for (int k = i + 1; k < j; k++)
			res = min(res, memdp(dp, A, i, k) + memdp(dp, A, k, j) + A[i] * A[j] * A[k]);
		dp[i][j] = res;
		return res;
	}
};
