#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
	{
		int N = words.size();
		vector<int> wordsScore(N);
		for (int i = 0; i < N; ++i)
		{
			for (auto c : words[i])
				wordsScore[i] += score[c - 'a'];
		}
		vector<int> letter(26);
		for (auto c : letters)
			++letter[c - 'a'];
		vector<map<vector<int>, int>> dp(N + 1); //{count mask,score}
		dp[0][vector<int>(26)] = 0;
		for (int i = 0; i < N; ++i)
		{
			for (auto &iter : dp[i])
			{
				vector<int> count = iter.first;
				dp[i + 1][iter.first] = iter.second;
				int j = 0;
				for (; j < (int)words[i].length(); ++j)
				{
					int index = words[i][j] - 'a';
					++count[index];
					if (count[index] > letter[index])
						break;
				}
				if (j == (int)words[i].length())
					dp[i + 1][count] = max(dp[i + 1][count], iter.second + wordsScore[i]);
			}
		}
		int res = 0;
		for (auto iter : dp.back())
			res = max(res, iter.second);
		return res;
	}
};