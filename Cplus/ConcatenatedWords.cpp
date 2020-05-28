#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
	{
		unordered_set<string> s(words.begin(), words.end());
		vector<string> res;
		for (auto &word : words)
		{
			vector<int> dp(word.length());
			for (int i = 1; i < (int)word.length(); i++)
			{
				if (s.find(word.substr(0, i)) != s.end() && backTracking(s, word, i, dp))
				{
					res.push_back(word);
					break;
				}
			}
		}
		return res;
	}

	bool backTracking(unordered_set<string> &s, string &word, int index, vector<int> &dp)
	{
		int n = word.length();
		if (index >= n)
			return true;
		if (dp[index] != 0)
			return dp[index] == 1;
		for (int i = index; i < n; i++)
		{
			if (s.find(word.substr(index, i - index + 1)) != s.end())
			{
				if (backTracking(s, word, i + 1, dp))
					return true;
			}
		}
		dp[index] = -1;
		return false;
	}
};