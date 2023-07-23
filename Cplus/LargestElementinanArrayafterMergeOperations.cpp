#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxArrayValue(vector<int> &nums)
	{
		long long res = *max_element(nums.begin(), nums.end()), N = nums.size();
		for (int i = N - 1, j = N - 2; i >= 0;)
		{
			long long sum = nums[i];
			for (; j >= 0 && nums[j] <= sum; --j)
				sum += nums[j];
			i = j;
			--j;
			res = max(res, sum);
		}
		return res;
	}
};