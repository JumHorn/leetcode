#include<vector>
using namespace std;

class Solution
{
public:
	long long countAlternatingSubarrays(vector<int> &nums)
	{
		long long res = 0;
		int pre = nums[0], len = 1;
		for (auto n : nums)
		{
			if (pre == n)
				len = 1;
			else
				++len;
			pre = n;
			res += len;
		}
		return res;
	}
};