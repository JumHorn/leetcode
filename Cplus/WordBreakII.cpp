#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> wordBreak(string s, vector<string> &wordDict)
	{
		int N = s.length();
		vector<bool> breakarray(N + 1);
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		if (!canBreak(s, dict, breakarray))
			return {};
		vector<vector<string>> dp(N + 1);
		dp[0] = {""};
		for (int i = 0; i < N; ++i)
		{
			for (int j = i; j >= 0; --j)
			{
				if (!breakarray[j])
					continue;
				string word = s.substr(j, i - j + 1);
				if (dict.find(word) != dict.end())
				{
					for (auto &str : dp[j])
					{
						if (str.empty())
							dp[i + 1].push_back(word);
						else
							dp[i + 1].push_back(str + " " + word);
					}
				}
			}
		}
		return dp.back();
	}

	bool canBreak(const string &s, unordered_set<string> &dict, vector<bool> &dp)
	{
		dp[0] = true;
		for (int i = 0; i < (int)s.length(); ++i)
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