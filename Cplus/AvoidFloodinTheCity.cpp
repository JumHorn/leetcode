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
		vector<int> res(n);
		for (int i = 0; i < n; i++)
			res[i] = rains[i] > 0 ? -1 : 0;
		unordered_map<int, int> m;
		set<int> dry;
		for (int i = 0; i < n; i++)
		{
			if (rains[i] > 0)
			{
				if (m.find(rains[i]) == m.end())
				{
					m[rains[i]] = i;
				}
				else
				{
					if (dry.empty())
						return {};
					auto iter = upper_bound(dry.begin(), dry.end(), m[rains[i]]);
					if (iter == dry.end())
						return {};

					res[*iter] = rains[i];
					dry.erase(iter);
					m[rains[i]] = i;
				}
			}
			else
			{
				dry.insert(i);
			}
		}
		for (auto n : dry)
			res[n] = 1;
		return res;
	}
};
