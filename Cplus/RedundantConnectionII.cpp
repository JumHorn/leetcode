#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
	{
		int N = edges.size(), twoParentsNode = -1; //two parent node
		vector<vector<int>> graph(N + 1);
		vector<int> res, seen(N + 1);
		for (auto &edge : edges)
		{
			if (seen[edge[0]] == 1 && seen[edge[1]] == 1)
				res = edge;
			seen[edge[0]] = seen[edge[1]] = 1;
			graph[edge[1]].push_back(edge[0]);
			if (graph[edge[1]].size() > 1u)
				twoParentsNode = edge[1];
		}
		if (twoParentsNode == -1)
			return res;
		int id = graph[twoParentsNode][0];
		while (!graph[id].empty() && id != twoParentsNode)
			id = graph[id][0];
		if (id == twoParentsNode) //circle
			return {graph[twoParentsNode][0], twoParentsNode};
		return {graph[twoParentsNode][1], twoParentsNode};
	}
};