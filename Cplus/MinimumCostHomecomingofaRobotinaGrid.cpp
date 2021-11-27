#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts)
	{
		int res = 0;
		int sx = startPos[0], sy = startPos[1], hx = homePos[0], hy = homePos[1];
		if (sx <= hx)
		{
			for (int i = sx + 1; i <= hx; ++i)
				res += rowCosts[i];
		}
		else
		{
			for (int i = sx - 1; i >= hx; --i)
				res += rowCosts[i];
		}

		if (sy <= hy)
		{
			for (int j = sy + 1; j <= hy; ++j)
				res += colCosts[j];
		}
		else
		{
			for (int j = sy - 1; j >= hy; --j)
				res += colCosts[j];
		}

		return res;
	}
};