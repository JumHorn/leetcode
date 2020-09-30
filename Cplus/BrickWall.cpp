#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int leastBricks(vector<vector<int>> &wall)
	{
		unordered_map<int, int> m; //{edge,crossed walls}
		for (int i = 0; i < (int)wall.size(); ++i)
		{
			int prefixsum = 0;
			for (int j = 0; j < (int)wall[i].size() - 1; ++j)
			{
				prefixsum += wall[i][j];
				if (m.find(prefixsum) == m.end())
					m[prefixsum] = i - 1;
				else
					--m[prefixsum];
			}
			for (auto &n : m)
				++n.second;
		}
		int res = wall.size();
		for (auto &n : m)
			res = min(res, n.second);
		return res;
	}
};