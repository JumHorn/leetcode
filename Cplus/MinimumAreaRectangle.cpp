#include <algorithm>
#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minAreaRect(vector<vector<int>> &points)
	{
		int res = INT_MAX, n = points.size();
		set<pair<int, int>> s;
		for (auto &point : points)
			s.insert({point[0], point[1]});
		for (auto &p1 : points)
		{
			int x1 = p1[0], y1 = p1[1];
			for (auto &p2 : points)
			{
				int x2 = p2[0], y2 = p2[1];
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