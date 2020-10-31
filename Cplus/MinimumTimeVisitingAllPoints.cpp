#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int minTimeToVisitAllPoints(vector<vector<int>> &points)
	{
		int res = 0;
		for (int i = 1; i < (int)points.size(); ++i)
		{
			int a = abs(points[i][0] - points[i - 1][0]), b = abs(points[i][1] - points[i - 1][1]);
			res += min(a, b) + abs(a - b);
		}
		return res;
	}
};