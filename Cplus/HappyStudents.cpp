#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countWays(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int res = 0, count = 0, pre = -1;
		for (auto n : nums)
		{
			if (n > count && count > pre)
				++res;
			pre = n;
			++count;
		}
		return res + (pre < count ? 1 : 0);
	}
};