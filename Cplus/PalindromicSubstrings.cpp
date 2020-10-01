#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSubstrings(string s)
	{
		int N = s.length(), res = N;
		vector<vector<bool>> dp(N, vector<bool>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			dp[i][i] = true;
			for (int j = i + 1; j < N; ++j)
			{
				if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
				{
					dp[i][j] = true;
					++res;
				}
			}
		}
		return res;
	}
};