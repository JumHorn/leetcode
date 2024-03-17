#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumMoves(vector<int> &nums, int k, int maxChanges)
	{
		long long res = LLONG_MAX, N = nums.size(), c = 0; // continous 1;
		vector<long long> pos, prefix = {0};			   // prefix sum of pos
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == 1)
			{
				pos.push_back(i);
				prefix.push_back(prefix.back() + i);
				c = max(c, 1LL);
				if (i > 0 && nums[i - 1] == 1)
				{
					c = max(c, 2LL);
					if (i > 1 && nums[i - 2] == 1)
						c = 3;
				}
			}
		}
		c = min(c, (long long)k);
		if (maxChanges >= k - c)
			return max(0LL, c - 1) + (k - c) * 2;
		k -= maxChanges;
		for (int i = k - 1; i < (int)pos.size(); ++i)
		{
			int l = i - k + 1, /*left*/ r = i, /*right*/ p = l + k / 2 /*mid*/;
			long long sum = pos[p] * (p - l) - (prefix[p + 1] - prefix[l]) + (prefix[r + 1] - prefix[p]) - pos[p] * (r - p);
			res = min(res, sum);
		}
		return res + maxChanges * 2;
	}
};