#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minScoreTriangulation(vector<int> &A)
	{
		int N = A.size();
		vector<vector<int>> dp(N, vector<int>(N));
		return memdp(A, 0, N - 1, dp);
	}

	int memdp(vector<int> &A, int first, int last, vector<vector<int>> &dp)
	{
		if (first + 1 >= last)
			return 0;
		if (dp[first][last] != 0)
			return dp[first][last];
		int res = INT_MAX;
		for (int k = first + 1; k < last; ++k)
			res = min(res, memdp(A, first, k, dp) + memdp(A, k, last, dp) + A[first] * A[last] * A[k]);
		dp[first][last] = res;
		return res;
	}
};