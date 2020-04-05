#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> minSubsequence(vector<int>& nums)
	{
		make_heap(nums.begin(), nums.end());
		int sum = accumulate(nums.begin(), nums.end(), 0), tmp = 0;
		vector<int> res;
		for (int i = nums.size() - 1; i >= 0 && tmp <= sum - tmp; --i)
		{
			pop_heap(nums.begin(), nums.begin() + i + 1);
			tmp += nums[i];
			res.push_back(nums[i]);
		}
		return res;
	}
};
