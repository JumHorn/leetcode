#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
private:
	struct Point
	{
		double x;
		double y;
	};

public:
	int numPoints(vector<vector<int>> &points, int r)
	{
		PRECIOUSE = 1e-5;
		int res = 1, N = points.size();
		for (int i = 0; i < N - 1; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (hypot(points[i][0] - points[j][0], points[i][1] - points[j][1]) - 2 * r > PRECIOUSE)
					continue;
				// calc two circle center
				auto center = getCircleCenter(points[i], points[j], r);
				int a = 0, b = 0;
				for (int k = 0; k < N; ++k)
				{
					if (isInCircle(center.first, points[k], r))
						++a;
					if (isInCircle(center.second, points[k], r))
						++b;
				}
				res = max({res, a, b});
			}
		}
		return res;
	}

	bool isInCircle(Point &c, vector<int> &p, int R)
	{
		return (c.x - p[0]) * (c.x - p[0]) + (c.y - p[1]) * (c.y - p[1]) - R * R <= PRECIOUSE;
	}

	pair<Point, Point> getCircleCenter(vector<int> &A, vector<int> &B, int R)
	{
		double midx = (A[0] + B[0]) / 2.0, midy = (A[1] + B[1]) / 2.0;
		double val = hypot(midx - A[0], midy - A[1]);
		double d = sqrt(R * R - val * val);
		double theta = atan2(A[1] - B[1], A[0] - B[0]);
		pair<Point, Point> res;
		res.first.x = midx - d * sin(theta);
		res.first.y = midy + d * cos(theta);
		res.second.x = midx + d * sin(theta);
		res.second.y = midy - d * cos(theta);
		return res;
	}

private:
	double PRECIOUSE;
};