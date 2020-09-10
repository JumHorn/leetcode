#include <algorithm>
#include <cfloat>
#include <cmath>
#include <vector>
using namespace std;

/*
geometric median
*/

class Solution
{
public:
	double getMinDistSum(vector<vector<int>> &positions)
	{
		double left = 100, bottom = 100, right = 0, top = 0;
		for (auto &p : positions)
		{
			left = min(left, (double)p[0]);
			bottom = min(bottom, (double)p[1]);
			right = max(right, (double)p[0]);
			top = max(top, (double)p[1]);
		}
		double res = DBL_MAX, min_x = 0, min_y = 0;
		for (double delta = 10; delta >= 0.00001; delta /= 10)
		{
			for (double x = left; x <= right; x += delta)
			{
				for (double y = bottom; y <= top; y += delta)
				{
					double d = 0;
					for (auto &p : positions)
						d += hypot(p[0] - x, p[1] - y);
					if (res > d)
					{
						res = d;
						min_x = x;
						min_y = y;
					}
				}
			}
			left = min_x - delta;
			bottom = min_y - delta;
			right = min_x + delta;
			top = min_y + delta;
		}
		return res == DBL_MAX ? 0 : res;
	}
};