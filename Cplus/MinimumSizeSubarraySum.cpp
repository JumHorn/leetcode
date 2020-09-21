#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSubArrayLen(int s, vector<int> &nums)
	{
		int N = nums.size(), res = N;
		for (int i = 1; i < N; ++i) //prefix sum
			nums[i] += nums[i - 1];
		if (nums.empty() || nums.back() < s)
			return 0;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (nums[i] < s)
				continue;
			while (nums[i] - nums[j] >= s)
				++j;
			res = min(res, i - j + 1);
		}
		return res;
	}
};