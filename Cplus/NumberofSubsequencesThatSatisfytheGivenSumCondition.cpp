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
		for (int i = 0, j = N - 1; i <= j;)
		{
			if (nums[i] + nums[j] > target)
				--j;
			else
				res = (res + pow2[j - i++]) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};