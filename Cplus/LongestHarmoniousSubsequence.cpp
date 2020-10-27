#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLHS(vector<int> &nums)
	{
		map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		auto iter = m.begin(), pre = iter;
		int res = 0;
		for (++iter; iter != m.end(); ++iter)
		{
			if (iter->first - pre->first == 1)
				res = max(res, iter->second + pre->second);
			pre = iter;
		}
		return res;
	}
};