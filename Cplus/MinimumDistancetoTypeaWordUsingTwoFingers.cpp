#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDistance(string word)
	{
		vector<vector<vector<int>>> dp(word.size(), vector<vector<int>>(26, vector<int>(26, -1)));
		int res = INT_MAX;
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
				res = min(res, memdp(word, 0, i, j, dp));
		}
		return res;
	}

	int memdp(const string &word, int index, int finger1, int finger2, vector<vector<vector<int>>> &dp)
	{
		if (index >= (int)word.size())
			return 0;
		if (dp[index][finger1][finger2] != -1)
			return dp[index][finger1][finger2];
		return dp[index][finger1][finger2] =
				   min(distance(finger1, word[index] - 'A') + memdp(word, index + 1, word[index] - 'A', finger2, dp),
					   distance(finger2, word[index] - 'A') + memdp(word, index + 1, finger1, word[index] - 'A', dp));
	}

	int distance(int pos1, int pos2)
	{
		return abs(pos1 % 6 - pos2 % 6) + abs(pos1 / 6 - pos2 / 6);
	}
};