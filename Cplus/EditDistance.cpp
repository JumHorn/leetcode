#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int M = word1.size(), N = word2.size();
		vector<int> dp(N + 1);
		for (int j = 0; j < N; ++j)
			dp[j + 1] = dp[j] + 1;
		for (int i = 0; i < M; ++i)
		{
			int pre = dp[0];
			dp[0] = i + 1;
			for (int j = 0; j < N; ++j)
			{
				int next = dp[j + 1];
				if (word1[i] == word2[j])
					dp[j + 1] = pre;
				else
					dp[j + 1] = min({pre, dp[j], dp[j + 1]}) + 1;
				pre = next;
			}
		}
		return dp[N];
	}
};