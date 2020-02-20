#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestArithSeqLength(vector<int> &A)
	{
		int n = A.size(), res = 0;
		vector<unordered_map<int, int>> dp(n);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int diff = A[i] - A[j];
				dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
				res = max(res, dp[i][diff]);
			}
		}
		return res + 1;
	}
};