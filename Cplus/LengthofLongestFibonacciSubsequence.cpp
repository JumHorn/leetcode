#include <vector>
using namespace std;

class Solution
{
public:
	int lenLongestFibSubseq(vector<int> &A)
	{
		int res = 0, N = A.size();
		vector<vector<int>> dp(N, vector<int>(N));
		for (int i = 2; i < N; ++i)
		{
			for (int l = 0, r = i - 1; l < r;)
			{
				int sum = A[l] + A[r];
				if (sum == A[i])
				{
					dp[i][r] = dp[r][l] + 1;
					res = max(res, dp[i][r]);
					++l;
				}
				else if (sum < A[i])
					++l;
				else
					--r;
			}
		}
		return res == 0 ? 0 : res + 2;
	}
};