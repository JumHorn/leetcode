#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	int maxEvents(vector<vector<int>> &events)
	{
		sort(events.begin(), events.end());
		priority_queue<int> q;
		int res = 0, d = events[0][0], n = events.size();
		for (int i = 0; i < n;)
		{
			if (events[i][0] <= d && events[i][1] >= d)
			{
				q.push(-events[i][1]);
				i++;
			}
			else
			{
				while (!q.empty())
				{
					int tmp = -q.top();
					q.pop();
					if (tmp >= d)
					{
						res++;
						d++;
						break;
					}
				}
				if (q.empty())
					d = events[i][0];
			}
		}
		while (!q.empty())
		{
			int tmp = -q.top();
			q.pop();
			if (tmp >= d)
			{
				res++;
				d++;
			}
		}
		return res;
	}
};