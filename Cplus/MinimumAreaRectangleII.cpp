#include <algorithm>
#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	double minAreaFreeRect(vector<vector<int>> &points)
	{
		int N = points.size();
		double res = INT_MAX;
		set<pair<int, int>> s;
		for (auto &point : points)
			s.insert({point[0], point[1]});
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i == j)
					continue;
				for (int k = 0; k < N; ++k)
				{
					if (i == k || j == k)
						continue;
					int x = points[j][0] + points[k][0] - points[i][0];
					int y = points[j][1] + points[k][1] - points[i][1];
					if (s.find({x, y}) != s.end())
					{
						//vector dot product
						int tmp = (points[j][0] - points[i][0]) * (points[k][0] - points[i][0]) +
								  (points[j][1] - points[i][1]) * (points[k][1] - points[i][1]);
						if (tmp == 0)
						{
							//vector cross product
							//get area of rectangle(shoelance formula)
							double area = 1.0 * points[i][0] * points[j][1] + points[j][0] * y +
										  x * points[k][1] + points[k][0] * points[i][1] -
										  points[j][0] * points[i][1] - x * points[j][1] -
										  points[k][0] * y - points[i][0] * points[k][1];
							if (area < 0)
								area = -area;
							res = min(res, area / 2.0);
						}
					}
				}
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};