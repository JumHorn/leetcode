#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMiddleIndex(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		sum -= nums[0];
		if (sum == 0)
			return 0;
		int prefix = 0;
		for (int i = 1; i < (int)nums.size(); ++i)
		{
			prefix += nums[i - 1];
			sum -= nums[i];
			if (prefix == sum)
				return i;
		}
		return -1;
	}
};