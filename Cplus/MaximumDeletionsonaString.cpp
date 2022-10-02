#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int deleteString(string s)
	{
		int N = s.length();
		// max length of string start with index i,j when s[i:] == s[j:]
		vector<vector<int>> table(N, vector<int>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			table[i][i] = 1;
			for (int j = i + 1; j < N; ++j)
			{
				if (s[i] == s[j])
					table[i][j] = (j == N - 1) ? 1 : (table[i + 1][j + 1] + 1);
			}
		}

		vector<int> dp(N + 1, 1);
		dp[N] = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (j - i <= table[i][j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		return dp[0];
	}
};