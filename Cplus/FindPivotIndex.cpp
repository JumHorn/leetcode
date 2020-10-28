#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int pivotIndex(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int prefixsum = 0;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (prefixsum == sum - prefixsum - nums[i])
				return i;
			prefixsum += nums[i];
		}
		return -1;
	}
};