#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	double minAreaFreeRect(vector<vector<int>>& points)
	{
		int n = points.size();
		double res = 2e10;
		set<vector<int>> m(points.begin(), points.end());
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					continue;
				for (int k = 0; k < n; k++)
				{
					if (i == k || j == k)
						continue;
					vector<int> p(2);
					p[0] = points[j][0] + points[k][0] - points[i][0];
					p[1] = points[j][1] + points[k][1] - points[i][1];
					if (m.find(p) != m.end())
					{
						//vector dot product
						int tmp = (points[j][0] - points[i][0]) * (points[k][0] - points[i][0]) +
								  (points[j][1] - points[i][1]) * (points[k][1] - points[i][1]);
						if (tmp == 0)
						{
							//vector cross product
							//get area of rectangle(shoelance formula)
							double area = 1.0 * points[i][0] * points[j][1] + points[j][0] * p[1] +
										  p[0] * points[k][1] + points[k][0] * points[i][1] -
										  points[j][0] * points[i][1] - p[0] * points[j][1] -
										  points[k][0] * p[1] - points[i][0] * points[k][1];
							if (area < 0)
								area = -area;
							res = min(res, area / 2.0);
						}
					}
				}
			}
		}
		return res == 2e10 ? 0 : res;
	}
};
