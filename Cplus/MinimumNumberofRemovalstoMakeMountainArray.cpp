#include <vector>
using namespace std;

/*
LIS longest increasing and longest decreasing array
*/

class Solution
{
public:
	int minimumMountainRemovals(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> prefix(N), suffix(N);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
					prefix[i] = max(prefix[j], prefix[i]);
			}
			++prefix[i];
		}
		for (int i = N - 1; i >= 0; --i)
		{
			for (int j = N - 1; j > i; --j)
			{
				if (nums[i] > nums[j])
					suffix[i] = max(suffix[j], suffix[i]);
			}
			++suffix[i];
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (prefix[i] >= 2 && suffix[i] >= 2)
				res = max(res, prefix[i] + suffix[i] - 1);
		}
		return N - res;
	}
};