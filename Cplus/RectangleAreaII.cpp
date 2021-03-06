#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*
Algorithm
Y axis line scan
*/

class Solution
{
public:
	int rectangleArea(vector<vector<int>> &rectangles)
	{
		unsigned long long res = 0;
		sort(rectangles.begin(), rectangles.end(), *this);
		for (unsigned long long y = 0; y != INT_MAX;)
		{
			bool flag = false;
			unsigned long long x = 0, xlen = 0, ystep = INT_MAX;
			for (int i = 0; i < (int)rectangles.size(); ++i)
			{
				if (rectangles[i][1] > (int)y)
					ystep = min((int)ystep, rectangles[i][1]);
				if ((int)y >= rectangles[i][1] && (int)y < rectangles[i][3] && rectangles[i][2] > (int)x)
				{
					flag = true;
					ystep = min((int)ystep, rectangles[i][3]);
					x = max((int)x, rectangles[i][0]);
					xlen += rectangles[i][2] - x;
					x = rectangles[i][2];
				}
			}
			if (flag)
				res += xlen * (ystep - y);
			y = ystep;
		}
		return res % MOD;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[0] < rhs[0];
	}

private:
	static const int MOD = 1e9 + 7;
};