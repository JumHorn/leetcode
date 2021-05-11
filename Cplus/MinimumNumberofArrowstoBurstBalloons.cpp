#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMinArrowShots(vector<vector<int>> &points)
	{
		if (points.empty())
			return 0;
		sort(points.begin(), points.end(), *this);
		int maxright = points[0][1], res = 1;
		for (auto &p : points)
		{
			if (p[0] > maxright)
			{
				++res;
				maxright = p[1];
			}
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};