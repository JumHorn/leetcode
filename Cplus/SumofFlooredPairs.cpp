#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfFlooredPairs(vector<int> &nums)
	{
		int N = nums.size();
		sort(nums.begin(), nums.end());
		long res = 0;
		for (int i = 0; i < N; ++i)
		{
			int j = i + 1, k = 1;
			for (; nums[i] * (k + 1) <= nums.back(); ++k)
			{
				auto iter = lower_bound(nums.begin() + j, nums.end(), nums[i] * (k + 1));
				int n = iter - nums.begin();
				res = (res + (n - j) * k) % MOD;
				j = n;
			}
			res = (res + (N - j) * k) % MOD;
		}
		// the equals
		for (int i = 0, j = 0; i < N;)
		{
			j = i + 1;
			while (j < N && nums[i] == nums[j])
				++j;
			if (j - i > 1)
				res = (res + (j - i) * (j - i - 1) / 2) % MOD;
			i = j;
		}
		return (res + N) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};