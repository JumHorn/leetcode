#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxTwoEvents(vector<vector<int>> &events)
	{
		auto f = [&](vector<int> &lhs, vector<int> &rhs)
		{
			return lhs[1] < rhs[1];
		};
		sort(events.begin(), events.end(), f);
		int res = 0, maxval = 0;
		map<int, int> m; //{index,maxval}
		for (auto &v : events)
		{
			res = max(res, v[2]);
			maxval = max(maxval, v[2]);
			auto iter = m.lower_bound(v[0]);
			if (iter != m.begin())
			{
				--iter;
				res = max(res, v[2] + iter->second);
			}
			m[v[1]] = max({m[v[1]], v[2], maxval});
		}
		return res;
	}
};