#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience)
	{
		int N = patience.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		queue<int> q;
		q.push(0);
		vector<int> seen(N), depth(N);
		seen[0] = 1;
		int d = 0;
		//BFS
		while (!q.empty())
		{
			++d;
			int size = q.size();
			while (--size >= 0)
			{
				int node = q.front();
				q.pop();
				for (auto n : graph[node])
				{
					if (seen[n] == 0)
					{
						seen[n] = 1;
						depth[n] = d;
						q.push(n);
					}
				}
			}
		}

		int res = 0;
		for (int i = 1; i < N; ++i)
		{
			int t = depth[i] * 2;
			int back = 0;
			if (patience[i] < t)
				back = t - (t % patience[i] ? t % patience[i] : patience[i]);
			res = max(res, t + back);
		}
		return res + 1;
	}
};