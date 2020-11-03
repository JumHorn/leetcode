#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> fallingSquares(vector<vector<int>> &positions)
	{
		if (positions.empty())
			return {};
		int n = positions.size();
		vector<int> res(n);
		map<pair<int, int>, int> areamap;
		res[0] = positions[0][1];
		areamap[{positions[0][0], positions[0][0] + positions[0][1]}] = positions[0][1];
		for (int i = 1; i < n; ++i)
		{
			int maxheight = 0;
			auto iter = areamap.lower_bound({positions[i][0], positions[i][0] + positions[i][1]});
			if (iter != areamap.begin())
			{
				--iter;
				if (iter->first.second > positions[i][0])
				{
					maxheight = max(maxheight, iter->second);
					areamap[{iter->first.first, positions[i][0]}] = iter->second;
					if (iter->first.second > positions[i][0] + positions[i][1])
						areamap[{positions[i][0] + positions[i][1], iter->first.second}] = iter->second;
					iter = areamap.erase(iter);
				}
				else
					++iter;
			}
			while (iter != areamap.end() && positions[i][0] + positions[i][1] > iter->first.first)
			{
				maxheight = max(maxheight, iter->second);
				if (positions[i][0] + positions[i][1] <= iter->first.second)
					areamap[{positions[i][0] + positions[i][1], iter->first.second}] = iter->second;
				iter = areamap.erase(iter);
			}
			res[i] = max(maxheight + positions[i][1], res[i - 1]);
			areamap[{positions[i][0], positions[i][0] + positions[i][1]}] = maxheight + positions[i][1];
		}
		return res;
	}
};