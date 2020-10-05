#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLength(vector<int> &A, vector<int> &B)
	{
		int M = A.size(), N = B.size();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		int res = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (A[i] == B[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				res = max(res, dp[i + 1][j + 1]);
			}
		}
		return res;
	}
};