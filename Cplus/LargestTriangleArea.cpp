#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	double largestTriangleArea(vector<vector<int>> &points)
	{
		int N = points.size();
		double res = 0.0;
		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				for (int k = j + 1; k < N; ++k)
				{
					double area = triangleArea(points[i], points[j], points[k]);
					if (area > res)
						res = area;
				}
			}
		}
		return res;
	}

	double triangleArea(vector<int> &p1, vector<int> &p2, vector<int> &p3)
	{
		return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] +
						 p3[0] * p1[1] - p1[1] * p2[0] -
						 p2[1] * p3[0] - p3[1] * p1[0]);
	}
};