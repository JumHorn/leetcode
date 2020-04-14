#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
	int maxPoints(vector<vector<int>> &points)
	{
		int n = points.size();
		if (n < 2)
			return n;
		int res = 0;
		for (int i = 0; i < n - 1; i++)
		{
			map<pair<int, int>, int> data;
			int vertical = 0; //该点与x轴垂直的直线上有多少个点
			int slope = 0;	  //同斜率的直线点的个数
			int maxp = 0;	  //最多点数
			int samep = 1;	  //相同点,包含自身
			for (int j = i + 1; j < n; j++)
			{
				if (points[i] == points[j]) //测试用例的点有重复
					samep++;
				else if (points[i][0] == points[j][0])
					vertical++;
				else
				{
					//long double slope=(points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0]);//精度不够
					int a = points[i][1] - points[j][1], b = points[i][0] - points[j][0];
					int tmp = gcd(a, b);
					maxp = max(maxp, ++data[{a / tmp, b / tmp}]);
				}
			}
			maxp = max(maxp, vertical) + samep; //同斜率和垂直点中选出最大的点
			res = max(res, maxp);
		}
		return res;
	}

	int gcd(int x, int y)
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
};