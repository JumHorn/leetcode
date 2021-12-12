#include <vector>
using namespace std;

class Solution
{
public:
	long long subArrayRanges(vector<int> &nums)
	{
		long long res = 0;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			int maxval = nums[i], minval = nums[i];
			for (int j = i + 1; j < N; ++j)
			{
				maxval = max(maxval, nums[j]);
				minval = min(minval, nums[j]);
				res += maxval - minval;
			}
		}
		return res;
	}
};