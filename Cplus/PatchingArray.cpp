#include <vector>
using namespace std;

class Solution
{
public:
	int minPatches(vector<int> &nums, int n)
	{
		long m = 0, res = 0, N = nums.size();
		for (int i = 0; i < N && m < n;)
		{
			if (nums[i] - m > 1)
			{
				++res;
				m = 2 * m + 1;
			}
			else
				m += nums[i++];
		}
		for (; m < n; m = 2 * m + 1)
			++res;
		return res;
	}
};