#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSquareStreak(vector<int> &nums)
	{
		unordered_map<int, int> m; //{end val,streak length}
		sort(nums.begin(), nums.end());
		int res = -1;
		for (auto n : nums)
		{
			if (m.find(n) == m.end())
			{
				long r = isSquare(n);
				if (r * r == n)
				{
					auto it = m.find(r);
					if (it == m.end())
						m[n] = 1;
					else
						m[n] = it->second + 1;
				}
				else
					m[n] = 1;
			}
			if (m[n] >= 2)
				res = max(res, m[n]);
		}
		return res;
	}

	long isSquare(long n)
	{
		long lo = 0, hi = n;
		while (lo < hi)
		{
			long mi = (hi - lo) / 2 + lo;
			if (mi * mi < n)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};