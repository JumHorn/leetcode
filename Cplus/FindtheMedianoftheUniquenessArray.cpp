#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int medianOfUniquenessArray(vector<int> &nums)
	{
		long long N = nums.size(), total = N * (N + 1) / 2;
		int lo = 1, hi = N;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (atMostK(nums, mi) * 2 < total)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	long long atMostK(vector<int> &nums, int k)
	{
		unordered_map<int, int> m; //{val,freq}
		long long N = nums.size(), res = 0;
		for (int i = 0, j = 0; i < N; ++i)
		{
			++m[nums[i]];
			for (; m.size() > k; ++j)
			{
				if (--m[nums[j]] == 0)
					m.erase(nums[j]);
			}
			res += i - j + 1;
		}
		return res;
	}
};