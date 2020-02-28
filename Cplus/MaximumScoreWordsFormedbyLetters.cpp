#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
	{
		int n = words.size();
		vector<int> wordsscore(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (int)words[i].length(); j++)
				wordsscore[i] += score[words[i][j] - 'a'];
		}
		vector<int> letter(26);
		for (int i = 0; i < (int)letters.size(); i++)
			letter[letters[i] - 'a']++;
		vector<map<vector<int>, int>> dp(n + 1);
		dp[0][vector<int>(26)] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (auto iter : dp[i - 1])
			{
				vector<int> v = iter.first;
				dp[i][iter.first] = iter.second;
				int j = 0;
				for (; j < (int)words[i - 1].length(); j++)
				{
					int index = words[i - 1][j] - 'a';
					++v[index];
					if (v[index] > letter[index])
						break;
				}
				if (j == (int)words[i - 1].length())
					dp[i][v] = max(dp[i][v], iter.second + wordsscore[i - 1]);
			}
		}
		int res = 0;
		for (auto iter : dp.back())
			res = max(res, iter.second);
		return res;
	}
};