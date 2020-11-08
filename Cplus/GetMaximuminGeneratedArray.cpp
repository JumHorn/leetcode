#include <vector>
using namespace std;

class Solution
{
public:
	int getMaximumGenerated(int n)
	{
		if (n <= 1)
			return n;
		vector<int> nums(n + 1);
		nums[1] = 1;
		int res = 0;
		for (int i = 2; i <= n; ++i)
		{
			if (i % 2 == 0)
				nums[i] = nums[i / 2];
			else
				nums[i] = nums[i / 2] + nums[i / 2 + 1];
			res = max(res, nums[i]);
		}
		return res;
	}
};