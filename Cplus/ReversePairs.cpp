#include <vector>
using namespace std;

class Solution
{
public:
	int reversePairs(vector<int> &nums)
	{
		return divide(nums, 0, nums.size());
	}

	int divide(vector<int> &nums, int start, int end)
	{
		int res = 0;
		if (end - start <= 1)
			return 0;
		int mid = start + (end - start) / 2;
		res = divide(nums, start, mid) + divide(nums, mid, end);
		for (int i = start, j = mid; i < mid; i++)
		{
			while (j < end && (long)nums[i] - (long)nums[j] > (long)nums[j])
				j++;
			res += j - mid;
		}
		vector<int> dup(end - start);
		merge(nums.begin() + start, nums.begin() + mid, nums.begin() + mid, nums.begin() + end, dup.begin());
		copy(dup.begin(), dup.end(), nums.begin() + start);
		return res;
	}
};