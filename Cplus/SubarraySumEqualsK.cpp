#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
		int res = 0, prefixsum = 0;
		unordered_map<int, int> m; //{value,count}
		m[0] = 1;
		for (auto n : nums)
		{
			prefixsum += n;
			auto it = m.find(prefixsum - k);
			if (it != m.end())
				res += it->second;
			++m[prefixsum];
		}
		return res;
	}
};