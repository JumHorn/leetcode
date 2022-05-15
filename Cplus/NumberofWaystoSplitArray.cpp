#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int waysToSplitArray(vector<int> &nums)
	{
		long sum = accumulate(nums.begin(), nums.end(), 0LL), val = 0, N = nums.size();
		int res = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			val += nums[i];
			if (val >= sum - val)
				++res;
		}
		return res;
	}
};