#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int N1 = word1.length(), N2 = word2.length();
		vector<int> dp(N2 + 1);
		for (int j = 1; j <= N2; ++j)
			dp[j] = j;
		for (int i = 0; i < N1; ++i)
		{
			int pre = dp[0], next;
			dp[0] = i + 1;
			for (int j = 0; j < N2; ++j)
			{
				next = dp[j + 1];
				if (word1[i] == word2[j])
					dp[j + 1] = pre;
				else
					dp[j + 1] = min(dp[j + 1], dp[j]) + 1;
				pre = next;
			}
		}
		return dp[N2];
	}
};