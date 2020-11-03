#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> gridIllumination(int N, vector<vector<int>> &lamps, vector<vector<int>> &queries)
	{
		vector<int> res(queries.size());
		set<pair<int, int>> s;
		unordered_map<int, int> xmap, ymap, d0map, d1map;
		for (int i = 0; i < (int)lamps.size(); ++i)
		{
			++xmap[lamps[i][0]];
			++ymap[lamps[i][1]];
			++d0map[lamps[i][0] + lamps[i][1]];
			++d1map[lamps[i][0] - lamps[i][1]];
			s.insert({lamps[i][0], lamps[i][1]});
		}
		for (int i = 0; i < (int)queries.size(); ++i)
		{
			int x = queries[i][0], y = queries[i][1];
			if (xmap[x] != 0 || ymap[y] != 0 || d0map[x + y] != 0 || d1map[x - y] != 0)
			{
				res[i] = 1;
				for (int j = x - 1; j <= x + 1; j++)
				{
					for (int k = y - 1; k <= y + 1; k++)
					{
						if (s.find({j, k}) != s.end())
						{
							s.erase({j, k});
							--xmap[j];
							--ymap[k];
							--d0map[j + k];
							--d1map[j - k];
						}
					}
				}
			}
		}
		return res;
	}
};