#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
	{
		vector<unordered_set<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		vector<int> res(N), nodecount(N, 1);
		res[0] = postorder(graph, nodecount, 0);
		preorder(graph, nodecount, res, 0);
		return res;
	}

	void preorder(vector<unordered_set<int>> &graph, vector<int> &nodecount, vector<int> &dis, int node)
	{
		int N = graph.size();
		for (auto n : graph[node])
		{
			dis[n] = dis[node] + N - 2 * nodecount[n];
			preorder(graph, nodecount, dis, n);
		}
	}

	int postorder(vector<unordered_set<int>> &graph, vector<int> &nodecount, int node)
	{
		int res = 0;
		for (auto n : graph[node])
		{
			graph[n].erase(node);
			res += postorder(graph, nodecount, n);
			nodecount[node] += nodecount[n];
			res += nodecount[n];
		}
		return res;
	}
};