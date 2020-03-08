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
		for (int i = 0; i < n; i++)
			intervals[i].push_back(i);
		sort(intervals.begin(), intervals.end(), *this);
		vector<int> res(n);
		priority_queue<pair<int, int>> q;
		q.push({-intervals[0][1], 0});
		for (int i = 1; i < n; i++)
		{
			while (!q.empty())
			{
				if (intervals[q.top().second][1] > intervals[i][0])
					break;
				res[intervals[q.top().second][2]] = intervals[i][2];
				q.pop();
			}
			q.push({-intervals[i][1], i});
		}
		while (!q.empty())
		{
			res[intervals[q.top().second][2]] = -1;
			q.pop();
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		if (lhs[0] != rhs[0])
			return lhs[0] < rhs[0];
		return lhs[2] < rhs[2];
	}
};