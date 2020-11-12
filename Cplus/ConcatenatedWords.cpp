#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
	{
		unordered_set<string> dict;
		vector<string> res;
		sort(words.begin(), words.end(),
			 [](string &lhs, string &rhs) { return lhs.length() < rhs.length(); });
		for (auto &word : words)
		{
			if (canForm(dict, word))
				res.push_back(word);
			dict.insert(word);
		}
		return res;
	}

	bool canForm(unordered_set<string> &dict, string &word)
	{
		if (word.empty() || dict.empty())
			return false;
		int N = word.length();
		vector<int> dp(N + 1);
		dp[0] = true;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j < i && !dp[i]; ++j)
			{
				if (dp[j])
				{
					if (dict.find(word.substr(j, i - j)) != dict.end())
						dp[i] = true;
				}
			}
		}
		return dp[N];
	}
};