#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfGoodSubarraySplits(vector<int> &nums)
	{
		long long N = nums.size(), res = 1;
		int i = 0;
		while (i < N && nums[i] == 0)
			++i;
		if (i == N)
			return 0;
		for (int j = i++; i < N; ++i)
		{
			while (i < N && nums[i] == 0)
				++i;
			if (i < N)
				res = res * (i - j) % MOD;
			j = i;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};