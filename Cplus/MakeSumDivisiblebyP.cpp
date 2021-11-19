#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSubarray(vector<int> &nums, int p)
	{
		int N = nums.size();
		long r = 0, r1 = 0;
		for (auto n : nums)
			r = (n % p + r) % p;
		if (r == 0)
			return 0;
		unordered_map<int, int> m; //{remainder,index}
		m[0] = -1;
		int res = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			r1 = (r1 + nums[i] % p) % p;
			int diff = (r1 - r + p) % p;
			auto it = m.find(diff);
			if (it != m.end())
				res = min(res, i - it->second);
			m[r1] = i;
		}
		return res >= N ? -1 : res;
	}
};