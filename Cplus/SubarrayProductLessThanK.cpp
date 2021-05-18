#include <vector>
using namespace std;

class Solution
{
public:
	int numSubarrayProductLessThanK(vector<int> &nums, int k)
	{
		int res = 0, product = 1, N = nums.size();
		for (int i = 0, j = 0; i < N; ++i)
		{
			product *= nums[i];
			for (; j <= i && product >= k; ++j)
				product /= nums[j];
			res += i - j + 1;
		}
		return res;
	}
};