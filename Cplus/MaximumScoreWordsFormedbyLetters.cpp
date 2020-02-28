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
		for (int i = 1; i <= n; i++)
		{
			vector<int> v(26);
			for (int j = 0; j < 26; j++)
			{
				for (int k = 0; k <= letter[j]; k++)
				{
					//背包客问题，背包状态受到letter顺序的影响
					v[j] = k;
					vector<int> tmp(v);
					if (checkContains(tmp, words[i - 1]))
						dp[i][v] = dp[i - 1][tmp] + wordsscore[i - 1];
					dp[i][v] = max(dp[i][v], dp[i - 1][v]);
					if (i == 3)
						cout << dp[i][v] << endl;
				}
			}
		}
		return dp.back()[letter];
	}

	bool checkContains(vector<int> &v, string &s)
	{
		for (auto n : s)
			if (--v[n - 'a'] < 0)
				return false;
		return true;
	}
};

int main()
{
	vector<string> words = {"xxxz", "ax", "bx", "cx"};
	vector<char> letters = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
	vector<int> scores = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};
	Solution sol;
	int res = sol.maxScoreWords(words, letters, scores);
	return 0;
}
