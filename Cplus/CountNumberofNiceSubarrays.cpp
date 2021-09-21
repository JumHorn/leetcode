#include <unordered_map>
#include <vector>
using namespace std;

/*
map[val] openrator [] create non-exist val in map is a waste of time
*/

class Solution
{
public:
	int numberOfSubarrays(vector<int> &nums, int k)
	{
		int res = 0, odd = 0;
		unordered_map<int, int> m; //{odd value,count}
		m[0] = 1;
		for (auto n : nums)
		{
			odd += n % 2;
			auto iter = m.find(odd - k);
			if (iter != m.end())
				res += iter->second;
			++m[odd];
		}
		return res;
	}
};