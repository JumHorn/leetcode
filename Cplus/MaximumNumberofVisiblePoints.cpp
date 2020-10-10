#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

/*
几何问题大多用向量法求解

计算向量与x轴正方向夹角(求反余弦值在0-PI之间)
一四象限 向量乘以单位向量(1,0)
二三象限 向量乘以单位向量(-1,0)+PI
*/

#define PI (3.141592653)

class Solution
{
public:
	int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location)
	{
		double ang = angle / 180.0 * PI;
		vector<double> p;
		int repeat_location = 0;
		for (auto &point : points)
		{
			point[0] -= location[0];
			point[1] -= location[1];
			if (point[0] == 0 && point[1] == 0)
				++repeat_location;
			else
				p.push_back(angleToAxis(point));
		}
		sort(p.begin(), p.end());
		int res = 0, N = p.size();
		for (int i = 0; i < N; ++i)
			p.push_back(p[i] + 2 * PI);
		for (int i = 0, j = 0; i < 2 * N; ++i)
		{
			while (i < 2 * N && p[i] - p[j] <= ang)
				++i;
			res = max(res, i - j);
			++j;
		}
		return res + repeat_location;
	}

	double angleToAxis(vector<int> &point)
	{
		if (point[1] >= 0)
			return acos(point[0] * 1.0 / hypot(point[0], point[1]));
		else
			return acos(-point[0] * 1.0 / hypot(point[0], point[1])) + PI;
	}
};