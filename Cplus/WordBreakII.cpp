#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		if (!canBreak(s, wordDict))
			return {};
		int n = s.length();
		vector<unordered_set<string>> dp(n + 1);
		for (int i = 0; i < n; i++)
		{
			for (auto word : wordDict)
			{
				int len = word.length();
				if (word.length() <= i + 1)
				{
					if (word == s.substr(i + 1 - len, len))
					{
						if (i + 1 == len)
							dp[i + 1].insert(word);
						else
						{
							for (auto &prefix : dp[i + 1 - len])
								dp[i + 1].insert(prefix + " " + word);
						}
					}
				}
			}
		}
		return vector<string>(dp.back().begin(), dp.back().end());
	}

	bool canBreak(const string &s, vector<string> &wordDict)
	{
		vector<bool> dp(s.length() + 1);
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		dp[0] = true;
		for (int i = 0; i < (int)s.length(); i++)
		{
			for (int j = i; j >= 0 && !dp[i + 1]; j--)
			{
				if (dict.find(s.substr(j, i - j + 1)) != dict.end())
					dp[i + 1] = dp[i + 1] || dp[j];
			}
		}
		return dp.back();
	}
};