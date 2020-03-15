#include <vector>
using namespace std;

class Solution
{
public:
	int maxDistance(vector<vector<int>> &grid)
	{
		int res = -1, n = grid.size();
		vector<vector<int>> zero, one;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					one.push_back({i, j});
				else
					zero.push_back({i, j});
			}
		}

		for (int i = 0; i < (int)zero.size(); i++)
		{
			int dis = INT_MAX;
			for (int j = 0; j < (int)one.size(); j++)
				dis = min(dis, abs(zero[i][0] - one[j][0]) + abs(zero[i][1] - one[j][1]));
			res = max(res, dis);
		}
		return res == INT_MAX ? -1 : res;
	}
};
