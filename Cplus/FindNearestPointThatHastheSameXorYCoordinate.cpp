#include <vector>
using namespace std;

class Solution
{
public:
	int nearestValidPoint(int x, int y, vector<vector<int>> &points)
	{
		int res = -1;
		for (int i = 0; i < (int)points.size(); ++i)
		{
			if (points[i][0] == x || points[i][1] == y)
			{
				if (res == -1 || abs(points[i][0] - x) + abs(points[i][1] - y) < abs(points[res][0] - x) + abs(points[res][1] - y))
					res = i;
			}
		}
		return res;
	}
};