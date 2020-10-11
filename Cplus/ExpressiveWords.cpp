#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int expressiveWords(string S, vector<string> &words)
	{
		int res = 0;
		for (auto &word : words)
		{
			if (checkStretchy(S, word))
				++res;
		}
		return res;
	}

	bool checkStretchy(string &s, string &word)
	{
		int N = s.length(), W = word.length(), j = 0;
		for (int i = 0; i < N; ++i)
		{
			if (j < W && s[i] == word[j])
				++j;
			else if ((i <= 1 || s[i] != s[i - 2] || s[i] != s[i - 1]) && (i <= 0 || i >= N - 1 || s[i] != s[i + 1] || s[i] != s[i - 1]))
				return false;
		}
		return j == W;
	}
};