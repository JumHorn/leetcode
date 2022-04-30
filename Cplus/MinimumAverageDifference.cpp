#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumAverageDifference(vector<int> &nums)
	{
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);
		long long N = nums.size(), suffixsum = 0, res = 0, diff = sum;
		for (int i = N - 1; i >= 0; --i)
		{
			long long d1 = ((N - i - 1 != 0) ? suffixsum / (N - i - 1) : 0);
			long long d = abs(sum / (i + 1) - d1);
			if (d <= diff)
			{
				diff = d;
				res = i;
			}

			sum -= nums[i];
			suffixsum += nums[i];
		}
		return res;
	}
};