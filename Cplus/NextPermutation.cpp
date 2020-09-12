#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int> &nums)
	{
		int N = nums.size(), i = N;
		while (--i > 0)
		{
			if (nums[i] > nums[i - 1])
			{
				int j = N - 1;
				while (nums[j] <= nums[i - 1])
					--j;
				swap(nums[i - 1], nums[j]);
				reverse(nums.begin() + i, nums.end());
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};