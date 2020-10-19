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
				int lo = i, hi = N;
				while (lo < hi)
				{
					int mi = (hi - lo) / 2 + lo;
					if (nums[mi] > nums[i - 1])
						lo = mi + 1;
					else
						hi = mi;
				}
				swap(nums[i - 1], nums[lo - 1]);
				reverse(nums.begin() + i, nums.end());
				return;
			}
		}
		reverse(nums.begin(), nums.end());
	}
};