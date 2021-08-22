#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shortestCommonSupersequence(string str1, string str2)
	{
		int M = str1.length(), N = str2.length();
		vector<vector<int>> dp(M + 1, vector<int>(N + 1));
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (str1[i] == str2[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
		string res(M + N - dp[M][N], ' ');
		int i = M - 1, j = N - 1, k = (int)res.length() - 1;
		while (i >= 0 || j >= 0)
		{
			if (i < 0 || j < 0)
				res[k--] = i < 0 ? str2[j--] : str1[i--];
			else if (str1[i] == str2[j])
			{
				res[k--] = str1[i];
				--i;
				--j;
			}
			else
				res[k--] = dp[i][j + 1] > dp[i + 1][j] ? str1[i--] : str2[j--];
		}
		return res;
	}
};