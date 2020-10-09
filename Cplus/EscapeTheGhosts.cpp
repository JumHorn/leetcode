#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
	{
		int minstep = abs(target[0]) + abs(target[1]);
		for (auto &ghost : ghosts)
		{
			int ghoststep = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
			if (ghoststep <= minstep)
				return false;
		}
		return true;
	}
};