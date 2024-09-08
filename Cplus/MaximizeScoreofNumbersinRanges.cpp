#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPossibleScore(vector<int> &start, int d)
	{
		sort(start.begin(), start.end());
		int N = start.size();
		long long lo = 0, hi = start[N - 1] + d - start[0] + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (check(start, d, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool check(vector<int> &v, int d, long long gap)
	{
		long long N = v.size(), pre = v[0];
		for (int i = 1; i < N; ++i)
		{
			if (pre + gap > v[i] + d)
				return false;
			pre = max(pre + gap, (long long)v[i]);
		}
		return true;
	}
};