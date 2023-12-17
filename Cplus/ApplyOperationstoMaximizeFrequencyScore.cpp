#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxFrequencyScore(vector<int> &nums, long long k)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), lo = 0, hi = N + 1;
		vector<long long> prefix(N + 1);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] = prefix[i] + nums[i];

		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (canDo(prefix, k, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool canDo(vector<long long> &prefix, long long k, int window)
	{
		long long N = prefix.size() - 1;
		long long diff = 0;
		if (window % 2 == 1)
			diff = (prefix[window] - prefix[window / 2] - prefix[window / 2 + 1]);
		else
			diff = (prefix[window] - prefix[window / 2] - prefix[window / 2]);

		if (k - diff >= 0)
			return true;
		for (int i = window; i < N; ++i)
		{
			if (window % 2 == 1)
				diff = (prefix[i + 1] - prefix[i + 1 - window / 2] - (prefix[i - window / 2] - prefix[i + 1 - window]));
			else
				diff = (prefix[i + 1] - prefix[i + 1 - window / 2] - (prefix[i + 1 - window / 2] - prefix[i + 1 - window]));

			if (k - diff >= 0)
				return true;
		}
		return false;
	}
};