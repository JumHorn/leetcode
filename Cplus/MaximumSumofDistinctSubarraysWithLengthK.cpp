#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumSubarraySum(vector<int> &nums, int k)
	{
		long long res = 0, N = nums.size(), sum = 0;
		unordered_map<int, int> m; //{val,count}
		for (int i = 0; i < k; ++i)
		{
			sum += nums[i];
			++m[nums[i]];
		}
		if (m.size() == k)
			res = max(res, sum);
		for (int i = k; i < N; ++i)
		{
			sum -= nums[i - k];
			if (--m[nums[i - k]] == 0)
				m.erase(nums[i - k]);
			++m[nums[i]];
			sum += nums[i];
			if (m.size() == k)
				res = max(res, sum);
		}
		return res;
	}
};