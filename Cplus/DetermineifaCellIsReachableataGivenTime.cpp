#include <cmath>
using namespace std;

class Solution
{
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
	{
		int h = abs(sx - fx), v = abs(sy - fy);
		if (sx == fx && sy == fy)
			return t != 1;
		int t0 = min(h, v) + abs(h - v);
		return t0 <= t;
	}
};