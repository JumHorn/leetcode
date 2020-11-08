#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCut(string s)
	{
		int N = s.length();
		vector<int> cut(N + 1);
		vector<vector<bool>> dp(N, vector<bool>(N));
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = i; j < N; ++j)
				dp[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || dp[i + 1][j - 1])));
		}
		cut[0] = -1;
		for (int j = 0; j < N; ++j)
		{
			cut[j + 1] = N;
			for (int i = 0; i <= j; ++i)
			{
				if (dp[i][j])
					cut[j + 1] = min(cut[j + 1], cut[i] + 1);
			}
		}
		return cut[N];
	}
};