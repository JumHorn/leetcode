#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> outerTrees(vector<vector<int>> &points)
	{
		int N = points.size();
		sort(points.begin(), points.end());
		vector<int> seen(N);
		stack<int> s;
		// left to right
		int top = 0;
		for (int i = 1; i < N; ++i)
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
		dumpPoints(points, s, seen, res);

		// right to left
		top = N - 1;
		for (int i = N - 2; i >= 0; --i)
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

		dumpPoints(points, s, seen, res);
		return res;
	}

	void dumpPoints(vector<vector<int>> &points, stack<int> &s, vector<int> &seen, vector<vector<int>> &res)
	{
		for (; !s.empty(); s.pop())
		{
			if (seen[s.top()] == 0)
			{
				seen[s.top()] = 1;
				res.push_back(points[s.top()]);
			}
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