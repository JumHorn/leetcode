#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxEvents(vector<vector<int>> &events)
	{
		sort(events.begin(), events.end());
		priority_queue<int, vector<int>, greater<int>> q;
		int res = 0, d = 0, N = events.size();
		for (int i = 0; !q.empty() || i < N;)
		{
			if (q.empty())
				d = events[i][0];
			while (i < N && events[i][0] <= d)
				q.push(events[i++][1]);
			q.pop();
			++res;
			++d;
			while (!q.empty() && q.top() < d)
				q.pop();
		}
		return res;
	}
};