#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findPairs(vector<int> &nums, int k)
	{
		unordered_map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		int res = 0;
		if (k == 0)
		{
			for (auto n : m)
			{
				if (n.second > 1)
					++res;
			}
			return res;
		}
		for (auto n : m)
		{
			if (m.find(n.first - k) != m.end())
				++res;
		}
		return res;
	}
};