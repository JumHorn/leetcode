#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestStrChain(vector<string> &words)
	{
		int n = words.size();
		vector<vector<int>> charboard(n, vector<int>(26));
		sort(words.begin(), words.end(), *this);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (int)words[i].length(); j++)
				charboard[i][words[i][j] - 'a']++;
		}
		vector<int> dp(n, 1);
		int res = 1;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (words[i].length() - 1 == words[j].length())
				{
					if (checkValid(charboard[j], charboard[i]))
					{
						dp[i] = dp[j] + 1;
						res = max(res, dp[i]);
					}
				}
			}
		}
		return res;
	}

	bool checkValid(vector<int> &a, vector<int> &b)
	{
		for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i] > b[i])
				return false;
		}
		return true;
	}

	bool operator()(const string &lhs, const string &rhs)
	{
		return lhs.length() < rhs.length();
	}
};