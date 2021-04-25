#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxFrequency(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int res = 1, N = nums.size();
		long sum = k;
		for (int i = 1, j = 0; i < N; ++i)
		{
			sum -= long(nums[i] - nums[i - 1]) * (i - j);
			for (; j < i && sum < 0; ++j)
				sum += nums[i] - nums[j];
			res = max(res, i - j + 1);
		}
		return res;
	}
};