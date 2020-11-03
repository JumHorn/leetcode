#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s1.size() + s2.size() != s3.size())
			return false;
		if (s1.empty())
			return s2 == s3;
		if (s2.empty())
			return s1 == s3;
		int M = s1.size(), N = s2.size();
		vector<bool> dp(N + 1, false);
		dp[0] = true;
		for (int j = 0; j < N && s2[j] == s3[j]; j++)
			dp[j + 1] = true;
		for (int i = 0; i < M; ++i)
		{
			dp[0] = (dp[0] && s1[i] == s3[i]);
			for (int j = 0; j < N; j++)
				dp[j + 1] = (s1[i] == s3[i + j + 1] && dp[j + 1]) || (s2[j] == s3[i + j + 1] && dp[j]);
		}
		return dp[N];
	}
};