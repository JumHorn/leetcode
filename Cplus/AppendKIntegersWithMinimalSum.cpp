#include <vector>
using namespace std;

class Solution
{
public:
	long long minimalKSum(vector<int> &nums, int k)
	{
		long long res = 0, pre = 0;
		sort(nums.begin(), nums.end());
		for (auto n : nums)
		{
			if (n - pre > 1)
			{
				int m = n - pre - 1;
				if (m > k)
					m = k;
				res += ((pre + 1) + (pre + m)) * m / 2;
				k -= m;
			}
			pre = n;
			if (k == 0)
				break;
		}
		res += ((pre + 1) + (pre + k)) * k / 2;
		return res;
	}
};