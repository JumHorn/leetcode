#include <climits>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxValueOfEquation(vector<vector<int>> &points, int k)
	{
		int res = INT_MIN, N = points.size();
		deque<int> q;
		q.push_back(0);
		for (int i = 1; i < N; ++i)
		{
			while (!q.empty() && points[i][0] - points[q.front()][0] > k)
				q.pop_front();
			if (!q.empty())
				res = max(res, points[q.front()][1] + points[i][1] + points[i][0] - points[q.front()][0]);
			while (!q.empty() && points[i][1] - points[i][0] >= points[q.back()][1] - points[q.back()][0])
				q.pop_back();
			q.push_back(i);
		}
		return res;
	}
};