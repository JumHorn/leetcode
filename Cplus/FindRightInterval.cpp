#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findRightInterval(vector<vector<int>> &intervals)
	{
		int n = intervals.size();
		for (int i = 0; i < n; ++i)
			intervals[i].push_back(i);
		sort(intervals.begin(), intervals.end());
		vector<int> res(n);
		auto f = [&](int lhs, int rhs) { return intervals[lhs][1] > intervals[rhs][1]; };
		priority_queue<int, vector<int>, decltype(f)> q(f);
		if (!intervals.empty())
			q.push(0);
		for (int i = 1; i < n; ++i)
		{
			while (!q.empty() && intervals[q.top()][1] <= intervals[i][0])
			{
				res[intervals[q.top()][2]] = intervals[i][2];
				q.pop();
			}
			q.push(i);
		}
		while (!q.empty())
		{
			res[intervals[q.top()][2]] = -1;
			q.pop();
		}
		return res;
	}
};