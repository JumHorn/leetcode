#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
	{
		int N = queries.size();
		vector<int> res(N, -1);
		vector<pair<int, int>> v; //{val,index}
		for (int i = 0; i < N; ++i)
			v.push_back({queries[i], i});
		sort(v.begin(), v.end());
		sort(intervals.begin(), intervals.end());
		set<pair<int, int>> s; //{interval size,index}
		int M = intervals.size(), i = 0, j;
		while (i < M && intervals[i][1] < v[0].first)
			++i;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rmq; //{right,index}
		for (auto &[q, index] : v)
		{
			for (; i < M && q >= intervals[i][0]; ++i)
			{
				s.insert({intervals[i][1] - intervals[i][0] + 1, i});
				rmq.push({intervals[i][1], i});
			}
			while (!rmq.empty() && rmq.top().first < q)
			{
				int k = rmq.top().second;
				s.erase({intervals[k][1] - intervals[k][0] + 1, k});
				rmq.pop();
			}
			if (!s.empty())
				res[index] = s.begin()->first;
		}
		return res;
	}
};