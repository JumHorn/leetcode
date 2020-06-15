#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
	{
		int nodeindegree2 = -1, n = edges.size();
		vector<vector<int>> graph(n + 1);
		vector<int> res, seen(n + 1);
		for (int i = 0; i < n; i++)
		{
			if (seen[edges[i][0]] == 1 && seen[edges[i][1]] == 1)
				res = edges[i];
			seen[edges[i][0]] = seen[edges[i][1]] = 1;
			graph[edges[i][1]].push_back(edges[i][0]);
			if (graph[edges[i][1]].size() > 1)
				nodeindegree2 = edges[i][1];
		}
		if (nodeindegree2 == -1)
			return res;
		int id = graph[nodeindegree2][0];
		while (!graph[id].empty() && id != nodeindegree2)
			id = graph[id][0];
		if (id == nodeindegree2) //circle
			return {graph[nodeindegree2][0], nodeindegree2};
		return {graph[nodeindegree2][1], nodeindegree2};
	}
};