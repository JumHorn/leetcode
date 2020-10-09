#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> letterCasePermutation(string S)
	{
		vector<string> res;
		dfs(S, 0, res);
		return res;
	}

	void dfs(string &s, int index, vector<string> &res)
	{
		if (index >= (int)s.length())
		{
			res.push_back(s);
			return;
		}
		if (!isalpha(s[index]))
			return dfs(s, index + 1, res);
		char old = s[index];
		s[index] = tolower(s[index]);
		dfs(s, index + 1, res);
		s[index] = toupper(s[index]);
		dfs(s, index + 1, res);
		s[index] = old;
	}
};