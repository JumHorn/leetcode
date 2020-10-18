#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestArithSeqLength(vector<int> &A)
	{
		int N = A.size(), res = 0;
		vector<vector<int>> dp(N, vector<int>(1001)); //{diff,length}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				int diff = A[i] - A[j] + 500;
				dp[i][diff] = max(2, dp[j][diff] + 1);
				res = max(res, dp[i][diff]);
			}
		}
		return res;
	}
};