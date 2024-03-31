#include <climits>
#include <set>
#include <vector>
using namespace std;

/*
O(N) solution to calculate max Manhattan Distances
*/

class Solution
{
public:
	int minimumDistance(vector<vector<int>> &points)
	{
		multiset<int> xs, ys;
		for (auto &point : points)
		{
			int x = point[0] + point[1], y = point[1] - point[0];
			xs.insert(x);
			ys.insert(y);
		}

		int res = INT_MAX;
		for (auto &point : points)
		{
			int x = point[0] + point[1], y = point[1] - point[0];
			xs.erase(xs.find(x));
			ys.erase(ys.find(y));
			res = min(res, max(*xs.rbegin() - *xs.begin(), *ys.rbegin() - *ys.begin()));
			xs.insert(x);
			ys.insert(y);
		}
		return res;
	}
};