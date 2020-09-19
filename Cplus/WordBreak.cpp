#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool wordBreak(string s, vector<string> &wordDict)
	{
		int N = s.length();
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<bool> dp(N + 1);
		dp[0] = true;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j >= 0 && !dp[i + 1]; --j)
			{
				if (dict.find(s.substr(j, i - j + 1)) != dict.end())
					dp[i + 1] = dp[j];
			}
		}
		return dp.back();
	}
};