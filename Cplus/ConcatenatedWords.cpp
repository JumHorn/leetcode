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
			for (int i = 1; i < (int)word.length(); i++)
			{
				if (s.find(word.substr(0, i)) != s.end() && backTracking(s, word, i))
				{
					res.push_back(word);
					break;
				}
			}
		}
		return res;
	}

	bool backTracking(unordered_set<string> &s, string &word, int index)
	{
		int n = word.length();
		if (index >= n)
			return true;
		for (int i = index; i < n; i++)
		{
			if (s.find(word.substr(index, i - index + 1)) != s.end())
			{
				if (backTracking(s, word, i + 1))
					return true;
			}
		}
		return false;
	}
};