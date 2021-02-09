#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int waysToSplit(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		partial_sum(nums.begin(), nums.end(), nums.begin());
		for (int i = 0, j = 0, k = 0; i < N - 2; ++i)
		{
			while (j <= i || (j < N - 1 && nums[j] < nums[i] * 2))
				++j;
			while (k < j || (k < N - 1 && nums[k] - nums[i] <= nums[N - 1] - nums[k]))
				++k;
			res = (res + k - j) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};