#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minAreaRect(vector<vector<int>> &points)
	{
		int res = INT_MAX, n = points.size();
		set<vector<int>> s(points.begin(), points.end());
		for (int i = 0; i < n; i++)
		{
			int x1 = points[i][0], y1 = points[i][1];
			for (int j = 0; j < n; j++)
			{
				int x2 = points[j][0], y2 = points[j][1];
				if (x2 > x1 && y2 > y1)
				{
					if (s.find({x1, y2}) != s.end() && s.find({x2, y1}) != s.end())
						res = min(res, (x2 - x1) * (y2 - y1));
				}
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};