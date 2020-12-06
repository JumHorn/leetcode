#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxOperations(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), res = 0;
		for (int i = 0, j = N - 1; i < j;)
		{
			if (nums[i] + nums[j] == k)
			{
				++res;
				++i;
				--j;
			}
			else if (nums[i] + nums[j] < k)
				++i;
			else
				--j;
		}
		return res;
	}
};