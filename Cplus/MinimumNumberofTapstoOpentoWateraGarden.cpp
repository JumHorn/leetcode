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
		for (int i = 0; max(maxright, interval[i]) < n; ++i)
		{
			if (i > maxjump)
				return -1;
			maxright = max(maxright, interval[i]);
			if (i == maxjump)
			{
				++res;
				maxjump = maxright;
			}
		}
		return res + 1;
	}
};