#include <vector>
using namespace std;

class Solution
{
public:
	int isWinner(vector<int> &player1, vector<int> &player2)
	{
		int p1 = score(player1), p2 = score(player2);
		if (p1 == p2)
			return 0;
		return p1 > p2 ? 1 : 2;
	}

	int score(vector<int> &v)
	{
		int res = 0, N = v.size();
		for (int i = 0; i < N; ++i)
		{
			res += v[i];
			if ((i >= 1 && v[i - 1] == 10) || (i >= 2 && v[i - 2] == 10))
				res += v[i];
		}
		return res;
	}
};