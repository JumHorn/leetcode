#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> prefixsum(n + 1);
		for (int i = 0; i < n; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		int res = 0;
		for (int i = 0, j = 2; j <= n;)
		{
			if (prefixsum[j] - prefixsum[i] >= j - i - 1)
			{
				res = max(res, j - i - 1);
				++j;
			}
			else
			{
				++i;
				++j;
			}
		}
		return res;
	}
};
