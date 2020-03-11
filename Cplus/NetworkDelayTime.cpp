#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int N, int K)
	{
		vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));
		for (auto &t : times)
			graph[t[0]][t[1]] = t[2];
		vector<int> weight(N + 1, INT_MAX);
		priority_queue<pair<int, int>> q;
		q.push({0, K});
		while (!q.empty())
		{
			auto tmp = q.top();
			q.pop();
			weight[tmp.second] = min(weight[tmp.second], -tmp.first);
			for (int i = 1; i <= N; i++)
			{
				if (graph[tmp.second][i] != -1 && weight[i] == INT_MAX)
					q.push({tmp.first - graph[tmp.second][i], i});
			}
		}
		int res = *max_element(weight.begin() + 1, weight.end());
		return res == INT_MAX ? -1 : res;
	}
};