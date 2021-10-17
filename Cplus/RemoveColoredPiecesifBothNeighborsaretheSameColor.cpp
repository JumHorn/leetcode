#include <string>
using namespace std;

class Solution
{
public:
	bool winnerOfGame(string colors)
	{
		int alice = canbeRemoved(colors, 'A');
		int bob = canbeRemoved(colors, 'B');
		return alice > bob;
	}

	int canbeRemoved(string &colors, char c)
	{
		int res = 0, N = colors.size();
		for (int i = 0, j = 0; j < N; ++j)
		{
			while (j < N && colors[j] == c)
				++j;
			res += max(j - i - 2, 0);
			i = j + 1;
		}
		return res;
	}
};