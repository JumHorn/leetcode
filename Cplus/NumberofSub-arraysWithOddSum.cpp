#include <vector>
using namespace std;

class Solution
{
public:
	int numOfSubarrays(vector<int>& arr)
	{
		int N = arr.size(), res = 0;
		vector<vector<int>> dp(N, vector<int>(2));  //{odd,even}
		dp[0][0] = arr[0] % 2;
		dp[0][1] = 1 - dp[0][0];
		for (int i = 1; i < N; ++i)
		{
			if (arr[i] % 2 == 0)
			{
				dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
				dp[i][1] = (dp[i][1] + dp[i - 1][1] + 1) % MOD;
			}
			else
			{
				dp[i][0] = (dp[i][0] + dp[i - 1][1] + 1) % MOD;
				dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
			}
		}
		for (int i = 0; i < N; ++i)
			res = (res + dp[i][0]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
