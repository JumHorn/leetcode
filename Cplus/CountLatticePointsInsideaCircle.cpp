#include <vector>
using namespace std;

class Solution
{
public:
	int countLatticePoints(vector<vector<int>> &circles)
	{
		int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN, res = 0;
		for (auto &circle : circles)
		{
			int a = circle[0], b = circle[1], r = circle[2];
			x1 = min(x1, a - r);
			x2 = max(x2, a + r);
			y1 = min(y1, b - r);
			y2 = max(y2, b + r);
		}

		for (int i = x1; i <= x2; ++i)
		{
			for (int j = y1; j <= y2; ++j)
			{
				for (auto &circle : circles)
				{
					if (pointInCircle(circle, i, j))
					{
						++res;
						break;
					}
				}
			}
		}
		return res;
	}

	bool pointInCircle(vector<int> &circle, int x, int y)
	{
		int a = circle[0], b = circle[1], r = circle[2];
		return (a - x) * (a - x) + (b - y) * (b - y) <= r * r;
	}
};