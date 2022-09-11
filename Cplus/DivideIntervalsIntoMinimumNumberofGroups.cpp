#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minGroups(vector<vector<int>> &intervals)
	{
		multiset<int> s; //{end pos for each group}
		sort(intervals.begin(), intervals.end(), [&](vector<int> &lhs, vector<int> &rhs)
			 { return lhs[1] < rhs[1]; });
		for (auto &v : intervals)
		{
			int l = v[0], r = v[1];
			auto it = s.lower_bound(l);
			if (it != s.begin())
			{
				--it;
				s.erase(it);
			}
			s.insert(r);
		}
		return s.size();
	}
};