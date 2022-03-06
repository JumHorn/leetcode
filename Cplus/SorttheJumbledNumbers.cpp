#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
	{
		vector<pair<int, int>> v; //{maped value,index}
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			int val = 0, n = nums[i];
			if (n == 0)
			{
				v.push_back({mapping[0], i});
				continue;
			}
			for (int base = 1; n > 0; n /= 10, base *= 10)
				val += mapping[n % 10] * base;
			v.push_back({val, i});
		}

		sort(v.begin(), v.end());
		vector<int> res;
		for (auto [_, i] : v)
			res.push_back(nums[i]);
		return res;
	}
};