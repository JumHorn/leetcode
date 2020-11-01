#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> minSubsequence(vector<int> &nums)
	{
		make_heap(nums.begin(), nums.end());
		int sum = accumulate(nums.begin(), nums.end(), 0), prefixsum = 0;
		vector<int> res;
		for (int i = (int)nums.size() - 1; i >= 0 && prefixsum <= sum - prefixsum; --i)
		{
			pop_heap(nums.begin(), nums.begin() + i + 1);
			prefixsum += nums[i];
			res.push_back(nums[i]);
		}
		return res;
	}
};