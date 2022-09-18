#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
	{
		sort(players.begin(), players.end());
		sort(trainers.begin(), trainers.end(), greater<int>());
		int i = (int)players.size() - 1, res = 0;
		for (auto n : trainers)
		{
			while (i >= 0 && players[i] > n)
				--i;
			if (i < 0)
				break;
			++res;
			--i;
		}
		return res;
	}
};