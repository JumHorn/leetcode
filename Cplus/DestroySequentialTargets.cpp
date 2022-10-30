#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int destroyTargets(vector<int> &nums, int space)
	{
		unordered_map<int, pair<int, int>> m; //{remainder,{seed,count}}
		for (auto n : nums)
		{
			int r = n % space;
			if (m.count(r) == 0)
				m[r].first = n;
			else
				m[r].first = min(m[r].first, n);
			++m[r].second;
		}
		int seed = 0, count = 0;
		for (auto p : m)
		{
			if (p.second.second > count)
			{
				count = p.second.second;
				seed = p.second.first;
			}
			else if (p.second.second == count && p.second.first < seed)
				seed = p.second.first;
		}
		return seed;
	}
};