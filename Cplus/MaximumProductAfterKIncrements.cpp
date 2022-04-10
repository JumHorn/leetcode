#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumProduct(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		int pre = nums[0], i;
		for (i = 1; i < N; ++i)
		{
			int incr = (nums[i] - pre) * i;
			if (k < incr)
				break;
			pre = nums[i];
			k -= incr;
		}
		pre += k / i;
		k %= i;

		for (int j = 0; j < i; ++j)
			nums[j] = pre;
		for (int j = 0; j < k; ++j)
			++nums[j];

		long long res = 1;
		for (auto n : nums)
			res = res * n % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};