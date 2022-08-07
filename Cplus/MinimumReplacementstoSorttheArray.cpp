#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumReplacement(vector<int> &nums)
	{
		long long res = 0;
		int pre = nums.back(), N = nums.size();
		for (int i = N - 2; i >= 0; --i)
		{
			int k = (nums[i] + pre - 1) / pre;
			pre = nums[i] / k;
			res += k - 1;
		}
		return res;
	}
};