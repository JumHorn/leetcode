#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxUncrossedLines(vector<int> &A, vector<int> &B)
	{
		int n = A.size(), m = B.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int index = 0; index <= i; index++)
				{
					if (A[index] == B[j])
						dp[index + 1][j + 1] = max(dp[index + 1][j + 1], dp[index][j] + 1);
				}
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], max(dp[i + 1][j], dp[i][j + 1]));
			}
		}
		return dp.back().back();
	}
};