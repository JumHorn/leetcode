#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxFrequency(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int i = 1, j = 0, N = nums.size();
		long sum = k;
		for (; i < N; ++i)
		{
			sum -= long(nums[i] - nums[i - 1]) * (i - j);
			if (sum < 0)
				sum += nums[i] - nums[j++];
		}
		return i - j;
	}
};