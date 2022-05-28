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
		int N = word.size(), alldist = 0;
		vector<int> dp(26);
		for (int i = 0; i < N - 1; ++i)
		{
			int a = word[i] - 'A', b = word[i + 1] - 'A';
			for (int j = 0; j < 26; ++j)
				dp[a] = max(dp[a], dp[j] + distance(a, b) - distance(j, b));
			alldist += distance(a, b);
		}
		return alldist - *max_element(dp.begin(), dp.end());
	}

	int distance(int pos1, int pos2)
	{
		return abs(pos1 % 6 - pos2 % 6) + abs(pos1 / 6 - pos2 / 6);
	}
};