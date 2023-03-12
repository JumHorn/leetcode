#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long beautifulSubarrays(vector<int> &nums)
	{
		long long res = 0;
		unordered_map<int, int> m; //{mask,count}
		m[0] = 1;
		int mask = 0;
		for (auto n : nums)
		{
			mask ^= n;
			res += m[mask]++;
		}
		return res;
	}
};