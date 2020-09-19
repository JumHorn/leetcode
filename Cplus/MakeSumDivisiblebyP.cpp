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
		long r = 0;
		for (auto n : nums)
			r = (n % p + r) % p;
		if (r == 0)
			return 0;
		unordered_map<int, int> m; //{remainder,index}
		long r1 = 0;
		int res = INT_MAX;
		m[0] = -1;
		for (int i = 0; i < N; ++i)
		{
			r1 = (r1 + nums[i] % p) % p;
			int tmp = (r1 - r + p) % p;
			if (m.find(tmp) != m.end())
				res = min(res, i - m[tmp]);
			m[r1] = i;
		}
		return res >= N ? -1 : res;
	}
};