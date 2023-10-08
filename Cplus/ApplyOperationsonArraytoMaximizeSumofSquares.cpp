#include <vector>
using namespace std;

class Solution
{
public:
	int maxSum(vector<int> &nums, int k)
	{
		vector<int> cnt(30);
		for (auto n : nums)
		{
			for (int i = 0; i < 30; ++i)
			{
				if (n & (1 << i))
					++cnt[i];
			}
		}
		long long res = 0;
		for (; k > 0; --k)
		{
			long long val = 0;
			for (int i = 0; i < 30; ++i)
			{
				if (--cnt[i] >= 0)
					val |= (1 << i);
			}
			res = (res + val * val) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};