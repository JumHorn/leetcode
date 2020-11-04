#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubseq(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		long res = 0;
		int N = nums.size();
		vector<long> pow2(N + 1);
		pow2[0] = 1;
		for (int i = 0; i < N; ++i)
			pow2[i + 1] = pow2[i] * 2 % MOD;
		for (int i = 0, j = -1; i < N && nums[0] + nums[i] <= target; ++i)
		{
			if (2 * nums[i] <= target)
				res = (res + 1) % MOD;
			if (j < i - 1)
				++j;
			for (; j >= 0 && nums[j] + nums[i] > target;)
				--j;
			res = res + ((pow2[j + 1] - 1) % MOD) * (pow2[max(0, i - j - 1)] % MOD) % MOD;
		}
		return (res + MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};