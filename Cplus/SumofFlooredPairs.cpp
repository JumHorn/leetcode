#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfFlooredPairs(vector<int> &nums)
	{
		int MAXN = *max_element(nums.begin(), nums.end());
		vector<int> count(2 * MAXN + 1), prefixsum(2 * MAXN + 2);
		for (int n : nums)
			++count[n];
		for (int i = 0; i < 2 * MAXN; ++i)
			prefixsum[i + 1] = prefixsum[i] + count[i];

		long long res = 0LL;
		for (int i = 0; i <= MAXN; ++i)
		{
			if (count[i] == 0)
				continue;
			for (int j = i; j <= MAXN; j += i)
			{
				int r = j / i, cnt = prefixsum[j + i] - prefixsum[j];
				res += r * 1LL * cnt * count[i] % MOD;
				res %= MOD;
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};