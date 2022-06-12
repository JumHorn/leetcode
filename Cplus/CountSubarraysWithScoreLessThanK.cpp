#include <vector>
using namespace std;

class Solution
{
public:
	long long countSubarrays(vector<int> &nums, long long k)
	{
		long long res = 0, N = nums.size(), sum = 0;
		for (int i = 0, j = 0; i < N; ++i)
		{
			sum += nums[i];
			for (; j <= i && sum * (i - j + 1) >= k; ++j)
				sum -= nums[j];
			res += i - j + 1;
		}
		return res;
	}
};