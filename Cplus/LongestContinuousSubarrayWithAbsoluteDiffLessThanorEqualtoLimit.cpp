#include <numeric>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int> &nums, int limit)
	{
		int res = 0, N = nums.size(), i = 0, j = 0;
		multiset<int> s;
		for (; i < N; ++i)
		{
			s.insert(nums[i]);
			int maxval = *s.rbegin(), minval = *s.begin();
			if (maxval - minval > limit)
				s.erase(s.find(nums[j++]));
		}
		return i - j;
	}
};