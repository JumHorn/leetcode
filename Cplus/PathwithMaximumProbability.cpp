#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
	{
		vector<vector<pair<int, double>>> graph(n);
		for (int i = 0; i < (int)edges.size(); ++i)
		{
			graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
			graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
		}
		//dijkstra
		priority_queue<pair<double, int>> q;
		vector<int> seen(n);
		q.push({1.0, start});
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			seen[top.second] = 1;
			if (top.second == end)
				return top.first;
			for (auto &iter : graph[top.second])
			{
				if (seen[iter.first] == 0)
					q.push({iter.second * top.first, iter.first});
			}
		}
		return 0.0;
	}
};