#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minTaps(int n, vector<int> &ranges)
	{
		vector<int> interval(n + 1);
		for (int i = 0; i <= n; ++i)
			interval[max(0, i - ranges[i])] = max(interval[max(0, i - ranges[i])], i + ranges[i]);
		int res = 0, maxright = interval[0], maxjump = 0;
		if (maxright >= n)
			return 1;
		for (int i = 0; i <= n; ++i)
		{
			if (i > maxright)
				return -1;
			maxjump = max(maxjump, interval[i]);
			if (i == maxright)
			{
				++res;
				if (maxright >= n)
					return res;
				maxright = maxjump;
				if (maxright >= n)
					return res + 1;
			}
		}
		return -1;
	}
};