#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int expressiveWords(string S, vector<string> &words)
	{
		int res = 0;
		for (int i = 0; i < (int)words.size(); i++)
			res += checkStretchy(S, words[i]);
		return res;
	}

	int checkStretchy(string &s, string &word)
	{
		int n = s.length(), j = 0;
		if (word.size() > s.size())
			return 0;
		for (int i = 0; i < (int)word.length();)
		{
			if (j >= s.length() || word[i] != s[j])
				return 0;
			int k = j;
			while (i < (int)word.size() && j < (int)s.size() && s[k] == word[i] && s[k] == s[j])
			{
				i++;
				j++;
			}
			if (s[j] == s[k])
			{
				while (j < n && s[j] == s[k])
					j++;
				if (j - k < 3)
					return 0;
			}
		}
		return j == s.length() ? 1 : 0;
	}
};