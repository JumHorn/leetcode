#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> outerTrees(vector<vector<int>> &points)
	{
		int n = points.size();
		sort(points.begin(), points.end());
		vector<int> seen(n);
		stack<int> s;
		// left to right
		int top = 0;
		for (int i = 1; i < n; ++i)
		{
			while (!s.empty() && crossProduct(points[top], points[i], points[s.top()]) < 0)
			{
				top = s.top();
				s.pop();
			}
			s.push(top);
			top = i;
		}
		s.push(top);

		vector<vector<int>> res;
		dumpPoints(res, s, points, seen);

		// right to left
		top = n - 1;
		for (int i = n - 2; i >= 0; i--)
		{
			while (!s.empty() && crossProduct(points[top], points[i], points[s.top()]) < 0)
			{
				top = s.top();
				s.pop();
			}
			s.push(top);
			top = i;
		}
		s.push(top);

		dumpPoints(res, s, points, seen);
		return res;
	}

	void dumpPoints(vector<vector<int>> &res, stack<int> &s, vector<vector<int>> &points, vector<int> &seen)
	{
		while (!s.empty())
		{
			if (seen[s.top()] == 0)
			{
				seen[s.top()] = 1;
				res.push_back(points[s.top()]);
			}
			s.pop();
		}
	}

	int crossProduct(vector<int> &pointA, vector<int> &pointB, vector<int> &pointC)
	{
		int x1 = pointB[0] - pointA[0];
		int y1 = pointB[1] - pointA[1];
		int x2 = pointC[0] - pointA[0];
		int y2 = pointC[1] - pointA[1];
		return x1 * y2 - x2 * y1;
	}
};