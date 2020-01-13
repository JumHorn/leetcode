#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDistance(string word)
	{
		int dp[27][27][301] = {{{0}}};
		return minimumDistance(word, 0, 'A' - 1, 'A' - 1, dp);
	}

	int minimumDistance(const string &word, int index, char finger1, char finger2, int (*dp)[27][301])
	{
		if (index >= (int)word.size())
			return 0;
		if (dp[finger1 - 'A' + 1][finger2 - 'A' + 1][index] != 0)
			return dp[finger1 - 'A' + 1][finger2 - 'A' + 1][index];
		dp[finger1 - 'A' + 1][finger2 - 'A' + 1][index] =
			min(distance(finger1, word[index]) + minimumDistance(word, index + 1, word[index], finger2, dp),
				distance(finger2, word[index]) + minimumDistance(word, index + 1, finger1, word[index], dp));
		return dp[finger1 - 'A' + 1][finger2 - 'A' + 1][index];
	}

	int distance(char a, char b)
	{
		if (a == 'A' - 1)
			return 0;
		int ai = (a - 'A') / 6, aj = (a - 'A') % 6, bi = (b - 'A') / 6, bj = (b - 'A') % 6;
		return abs(ai - bi) + abs(aj - bj);
	}
};