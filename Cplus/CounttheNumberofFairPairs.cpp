#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countFairPairs(vector<int> &nums, int lower, int upper)
	{
		long long res = 0, N = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0, j = N - 1, k = N - 1; i < N - 1; ++i)
		{
			if (j <= i)
				j = i + 1;
			if (k <= i)
				k = i + 1;
			while (j > i && nums[i] + nums[j] >= lower)
				--j;
			while (k > i && nums[i] + nums[k] > upper)
				--k;
			res += k - j;
		}
		return res;
	}
};