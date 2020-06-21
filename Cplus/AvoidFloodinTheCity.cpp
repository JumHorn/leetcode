#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> avoidFlood(vector<int>& rains)
	{
		int n = rains.size();
		vector<int> res;
		unordered_map<int, int> m;
		set<int> dry;
		for (int i = 0; i < n; i++)
		{
			if (rains[i] > 0)
			{
				res.push_back(-1);
				if (m.find(rains[i]) != m.end())
				{
					if (dry.empty())
						return {};
					auto iter = dry.upper_bound(m[rains[i]]);
					if (iter == dry.end())
						return {};
					res[*iter] = rains[i];
					dry.erase(iter);
				}
				m[rains[i]] = i;
			}
			else
			{
				res.push_back(1);
				dry.insert(i);
			}
		}
		return res;
	}
};
