#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
	{
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		vector<int> res(N), nodecount(N, 1);
		res[0] = postorder(graph, -1, 0, nodecount);
		preorder(graph, nodecount, -1, 0, res);
		return res;
	}

	void preorder(vector<vector<int>> &graph, vector<int> &nodecount, int from, int at, vector<int> &dis)
	{
		int N = graph.size();
		for (auto to : graph[at])
		{
			if (from != to) //don't go back to parent
			{
				dis[to] = dis[at] + N - 2 * nodecount[to];
				preorder(graph, nodecount, at, to, dis);
			}
		}
	}

	int postorder(vector<vector<int>> &graph, int from, int at, vector<int> &nodecount)
	{
		int res = 0;
		for (auto to : graph[at])
		{
			if (from != to) //don't go back to parent
			{
				res += postorder(graph, at, to, nodecount);
				res += nodecount[to];

				nodecount[at] += nodecount[to];
			}
		}
		return res;
	}
};