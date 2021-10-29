#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> gridIllumination(int N, vector<vector<int>> &lamps, vector<vector<int>> &queries)
	{
		set<pair<int, int>> s;
		unordered_map<int, int> xmap, ymap, d0map, d1map;
		for (auto &lamp : lamps)
		{
			++xmap[lamp[0]];
			++ymap[lamp[1]];
			++d0map[lamp[0] + lamp[1]];
			++d1map[lamp[0] - lamp[1]];
			s.insert({lamp[0], lamp[1]});
		}

		vector<int> res;
		for (auto &query : queries)
		{
			res.push_back(0);
			int x = query[0], y = query[1];
			if (xmap[x] != 0 || ymap[y] != 0 || d0map[x + y] != 0 || d1map[x - y] != 0)
			{
				res.back() = 1;
				for (int i = x - 1; i <= x + 1; ++i)
				{
					for (int j = y - 1; j <= y + 1; ++j)
					{
						auto it = s.find({i, j});
						if (it != s.end())
						{
							s.erase(it);
							--xmap[i];
							--ymap[j];
							--d0map[i + j];
							--d1map[i - j];
						}
					}
				}
			}
		}
		return res;
	}
};