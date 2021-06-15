#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

/*
sort vector<vector<int>> much slower which is most time consuming
than sort vector<pair<int,int>>
*/

class Solution
{
public:
	int maxEvents(vector<vector<int>> &events)
	{
		priority_queue<int, vector<int>, greater<int>> q;
		int res = 0, d = 0, N = events.size();
		vector<pair<int, int>> v;
		for (auto &e : events)
			v.push_back({e[0], e[1]});
		sort(v.begin(), v.end());
		for (int i = 0; !q.empty() || i < N;)
		{
			if (q.empty())
				d = v[i].first;
			for (; i < N && v[i].first <= d; ++i)
				q.push(v[i].second);
			q.pop();
			++res;
			++d;
			while (!q.empty() && q.top() < d)
				q.pop();
		}
		return res;
	}
};