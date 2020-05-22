#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &A)
	{
		int n = A.size(), res = 0;
		vector<unordered_map<long, int>> dp(n);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				long diff = (long)A[i] - A[j];
				if (dp[j].find(diff) == dp[j].end())
					++dp[i][diff];
				else
				{
					dp[i][diff] += dp[j][diff] + 1;
					res += dp[j][diff];
				}
			}
		}
		return res;
	}
};