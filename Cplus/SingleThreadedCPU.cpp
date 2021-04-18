#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getOrder(vector<vector<int>> &tasks)
	{
		int N = tasks.size();
		for (int i = 0; i < N; ++i)
			tasks[i].push_back(i); //{enqueue,process,index}
		auto f = [](vector<int> &lhs, vector<int> &rhs) {
			if (lhs[0] != rhs[0])
				return lhs[0] < rhs[0];
			if (lhs[1] != rhs[1])
				return lhs[1] < rhs[1];
			return lhs[2] < rhs[2];
		};
		sort(tasks.begin(), tasks.end(), f);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		vector<int> res;
		long time = 0;
		for (int i = 0; i < N || !q.empty();)
		{
			for (; i < N && tasks[i][0] <= time; ++i)
				q.push({tasks[i][1], tasks[i][2]});
			if (!q.empty())
			{
				auto top = q.top();
				q.pop();
				res.push_back(top.second);
				time += top.first;
			}
			else if (i < N)
				time = tasks[i][0];
		}
		return res;
	}
};