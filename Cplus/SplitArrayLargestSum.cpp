#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int splitArray(vector<int> &nums, int m)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxval = *max_element(nums.begin(), nums.end());
		int lo = maxval, hi = sum;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (doSplit(nums, mi) > m)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int doSplit(vector<int> &nums, int maxsum)
	{
		int res = 0, sum = 0;
		for (auto n : nums)
		{
			if (sum + n > maxsum)
			{
				++res;
				sum = 0;
			}
			sum += n;
		}
		return res + (sum == 0 ? 0 : 1);
	}
};